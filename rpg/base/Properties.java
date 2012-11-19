package base;

public abstract class Properties {

	public Integer HP;
	public Integer MP;
	
	public Properties(Integer hp, Integer mp){
		this.HP = hp;
		this.MP = mp;
	}
	
	public abstract void setProperties(Properties p);	//使用多态性，定义自己的属性
}
