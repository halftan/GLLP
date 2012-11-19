package base;

public interface Actions {
	
	public boolean isAlive();
	public void takeDamage(Creature target, Properties damage);
	public void makeDamage(Creature source, Creature target, Properties damage);
	public void useItem(Creature source, Creature target, Properties effect);
	/*
	 * 自己再加入一些需要的方法
	 */
}
