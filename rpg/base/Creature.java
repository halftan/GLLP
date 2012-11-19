package base;

public abstract class Creature {

	public Integer cID; // 唯一识别码
	
	public String name;

	public Integer Sex;

	public Properties property;

	public boolean is_validate;

	public Creature(Integer ID) {
		this.cID = ID;
		this.name = null;
		this.Sex = null;
		this.property = null;
		this.is_validate = false;
	}

	public void setSex(Integer sex) {
		this.Sex = sex;
		if(this.name != null && this.property != null)
			this.is_validate = true;
	}

	public void setName(String name){
		this.name = name;
		if(this.Sex != null && this.property != null)
			this.is_validate = true;
	}
	
	public void setProperty(Properties p){
		this.property.setProperties(p);
		if(this.name != null && this.Sex != null)
			this.is_validate = true;
	}
	
	public static Integer MALE = 1;
	public static Integer FEMALE = 2;
}
