class Dough
{
	private String type = "";
	Dough(String t)
	{
		this.type = t;
	}

	public String getType()
	{
		return type;
	}
}

class Sauce
{
}

class Topping
{
}

class Pizza {
	private Dough dough;
	private Sauce sauce;
	private Topping topping;
 
	private boolean is_roasted = false;
	
	Pizza()
	{}

	public void setDough(String dough) {
		this.dough = dough;
	}
 
	public void setSauce(String sauce) {
		this.sauce = sauce;
	}
 
	public void setTopping(String topping) {
		this.topping = topping;
	}
}
 
/** "Abstract Builder" */
abstract class PizzaBuilder {
	protected Pizza pizza;
 
	public Pizza getPizza() {
		return pizza;
	}
 
	public void createNewPizzaProduct() {
		pizza = new Pizza();
	}
	public abstract void buildDough();
	public abstract void buildSauce();
	public abstract void buildTopping();
	public abstract void extraTreatment();
}

/** "ConcreteBuilder" */
class HawaiianPizzaBuilder extends PizzaBuilder {
	public void buildDough() {
		pizza.setDough("cross");
	}
	public void buildSauce() {
		pizza.setSauce("mild");
	}
	public void buildTopping() {
		pizza.setTopping("ham+pineapple");
	}
	public void roast()
	{
		is_roasted = true;
	}
	public void extraTreatment()
	{
		this.roast();
	}
}
 
/** "ConcreteBuilder" */
class SpicyPizzaBuilder extends PizzaBuilder {
	public void buildDough() {
		pizza.setDough("pan baked");
	}
 
	public void buildSauce() {
		pizza.setSauce("hot");
	}
 
	public void buildTopping() {
		pizza.setTopping("pepperoni+salami");
	}

	public void extraTreatment()
	{}
}

/** "Director" */
class Cook {
	private PizzaBuilder pizzaBuilder;

	public void setPizzaBuilder(PizzaBuilder pb) {
		pizzaBuilder = pb;
	}
	public Pizza getPizza() {
		return pizzaBuilder.getPizza();
	}
	public void constructPizza() {
		pizzaBuilder.createNewPizzaProduct();
		pizzaBuilder.buildDough();
		pizzaBuilder.buildSauce();
		pizzaBuilder.buildTopping();
		pizzaBuilder.extraTreatment();
	}
}
 
/** A given type of pizza being constructed. */
public class BuilderExample {
	public static void main(String[] args) {
		Cook cook = new Cook();
		PizzaBuilder hawaiianPizzaBuilder = new HawaiianPizzaBuilder();
		PizzaBuilder spicyPizzaBuilder = new SpicyPizzaBuilder();
 
		cook.setPizzaBuilder(hawaiianPizzaBuilder);
		cook.constructPizza();
		Pizza pizza = cook.getPizza(); // hawaiian

		cook.setPizzaBuilder(spicyPizzaBuilder);
		cook.constructPizza();

		pizza = cook.getPizza(); // spicy

		Pizza[] menu = new Pizza[150];
		
		cook.setPizzaBuilder(hawaiianPizzaBuilder);
		int i;
		for(i=0; i<100; i++)
		{
			cook.constructPizza();
			menu[i] = cook.getPizza();
		}
		cook.setPizzaBuilder(spicyPizzaBuilder);
		for(i=100;i<150;i++)
		{
			cook.constructPizza();
			menu[i] = cook.getPizza();
		}


	}
}

