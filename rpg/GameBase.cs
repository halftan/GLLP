using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LogicGame.GameBase
{
    /// <summary>
    /// 抽象基类  所有游戏类都继承于它
    /// </summary>
    public abstract class GameBase
    {
        protected string m_name;

        public GameBase()
        {
            m_name = "";
        }

        public string Name
        {
            get
            {
                return m_name;
            }
        }
    }

    /// <summary>
    /// 物品基类 
    /// </summary>
    public abstract class GameItem : GameBase
    {
        protected Double    m_Item_Weight;

        public GameItem()
        {
            m_Item_Weight=1.0;
            m_name="未知物品";
        }

    }

    /// <summary>
    /// 技能基类
    /// </summary>
    public abstract class Skill : GameBase
    {
        protected int m_mp_cost;
        
        public Skill()
        {
            m_name = "未知技能";
            m_mp_cost = 0;
        }
    }

    /// <summary>
    /// 角色 基类
    /// </summary>
    public abstract class Role : GameBase
    {
        protected int   m_hp;
        protected int   m_mp;

        protected int   m_PhysicsDEF;
        protected int   m_MagicalDEF;//魔法抗性  暂且不分魔法属性
        
        protected bool  m_allow_attacked;

        public Role()
        {
            m_hp = 100;
            m_mp = 0;
            m_PhysicsDEF = 0;
            m_MagicalDEF = 0;
            m_name = "未知角色";

        }

        public int HP
        {
            get
            {
               return m_hp;
            }
            set
            {
                m_hp = value;
            }
        }

        public int MP
        {
            get
            {
                return m_mp;
            }
            set
            {
                m_mp = value;
            }
        }

        public bool Allow_Attack
        {
            get
            {
                return m_allow_attacked;
            }
            set
            {
                m_allow_attacked = value;
            }
        }

        public int PhysicsDEF
        {
            get
            {
                return m_PhysicsDEF;
            }
            set
            {
                m_PhysicsDEF = value;
            }
        }

        public int MagicalDEF
        {
            get
            {
                return m_MagicalDEF;
            }
            set
            {
                m_MagicalDEF = value;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // 以下部分都有你们重写  我只是给个演示。。。 
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    public enum AttackResult
    {
        Hit,
        Miss,
        Crit,
        Absorb,
        Invalid
    }

    public enum AttackMode
    {
        Physics,
        Magic
    }
    /// <summary>
    /// 定义一个攻击的接口   所有具备攻击性的角色都需要实现该接口  你们根据自己的需要定义自己的接口
    /// 我只是做个简单的示范  
    /// </summary>
    public interface IAttack
    {
       AttackResult Attack(Role target,AttackMode attackmode);
    }

    /// <summary>
    /// 怪物类
    /// </summary>
    public class Monster : Role, IAttack
    {
        int m_normal_attack_power;

        public Monster(string _name,int _normal_attack_power,int _armor,int _magicalresistance,int _hp)
        {
            m_name = _name;
            m_allow_attacked = true;
            m_normal_attack_power = _normal_attack_power;
            m_PhysicsDEF = _armor;
            m_MagicalDEF = _magicalresistance;
            m_hp = _hp;
        }

        public AttackResult Attack(Role target, AttackMode attackmode)
        {
            return AttackResult.Invalid;
        }
    }

    /// <summary>
    /// NPC 类
    /// </summary>
    public class NPC : Role
    {
        public NPC()
        {
            m_allow_attacked = false;
        }
    }

    /// <summary>
    /// 玩家类
    /// </summary>
    public class Player : Role,IAttack
    {
        int m_PhysicsPower;
        int m_MagicPower;

        public Player(string _name,int _hp,int _mp,int _armor,int _magicalresistance)
        {
            m_name=_name;
            m_hp = _hp;
            m_mp = _mp;
            m_PhysicsDEF = _armor;
            m_MagicalDEF = _magicalresistance;
        }

        public void Set_Power(int PP,int MP)
        {
            m_PhysicsPower = PP;
            m_MagicPower = MP;
        }

        /// <summary>
        /// 简单实现接口
        /// </summary>
        /// <param name="target"></param>
        /// <param name="attackmode"></param>
        /// <returns></returns>
        public AttackResult Attack(Role target, AttackMode attackmode)
        {
            int damage=0;
            if (target.Allow_Attack)
            {
                if (attackmode == AttackMode.Physics)
                {
                    Random rd = new Random(0);
                    int r=rd.Next(2);

                    if (r == 1)
                    {
                        damage = m_PhysicsPower * 2 - target.PhysicsDEF;
                        if (damage > 0)
                            target.HP -= damage;
                        return AttackResult.Crit;
                    }

                    damage = m_PhysicsPower - target.PhysicsDEF;
                    if (damage > 0)
                        target.HP -= damage;
                    return AttackResult.Hit;
                            
                }
                else
                {
                    Random rd = new Random(0);
                    int r = rd.Next(10);

                    if (r == 1)
                    {
                        damage = m_MagicPower * 2 - target.MagicalDEF;
                        if (damage > 0)
                            target.HP -= damage;
                        return AttackResult.Crit;
                    }

                    damage = m_MagicPower - target.MagicalDEF;
                    if (damage > 0)
                    {
                        target.HP -= damage;
                        return AttackResult.Hit;
                    }
                    else return AttackResult.Absorb;

                }
            }
            else return AttackResult.Invalid;
        }
    }

    /*
    
    
     Monster m = new Monster("SnowWolf", 50, 15, 15, 200);
     Player p = new Player("小明", 500, 300, 30, 20);
     p.Set_Power(100, 100);
     p.Attack(m, AttackMode.Physics);
    
     */

}
