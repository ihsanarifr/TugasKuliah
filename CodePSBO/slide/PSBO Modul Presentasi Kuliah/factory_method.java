abstract class Pizza {
    public abstract int getPrice(); // count the cents
}
 
class HamAndMushroomPizza extends Pizza {
    public int getPrice() {
        return 850;
    }
}
 
class DeluxePizza extends Pizza {
    public int getPrice() {
        return 1050;
    }
}
 
class HawaiianPizza extends Pizza {
    public int getPrice() {
        return 1150;
    }
}
 
class PizzaFactory {
    public enum PizzaType {
        HamMushroom,
        Deluxe,
        Hawaiian
    }
 
    public static Pizza createPizza(PizzaType pizzaType) {
        switch (pizzaType) {
            case HamMushroom:
                return new HamAndMushroomPizza();
            case Deluxe:
                return new DeluxePizza();
            case Hawaiian:
                return new HawaiianPizza();
        }
        throw new IllegalArgumentException("The pizza type " + pizzaType + " is not recognized.");
    }
}
 
class PizzaLover {
    /*
     * Create all available pizzas and print their prices
     */
    public static void main (String args[]) {
        for (PizzaFactory.PizzaType pizzaType : 
		PizzaFactory.PizzaType.values()) {
            System.out.println("Price of " + 
			pizzaType + " is " + 
			PizzaFactory.createPizza(pizzaType).getPrice());
        }
    }
}
