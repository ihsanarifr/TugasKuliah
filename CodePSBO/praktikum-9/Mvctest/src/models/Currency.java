package models;

public class Currency {

    private float input;
    private float result;
    private float rate;

    public Currency() {
        input = 0;
        result = 0;
        rate = 0;
    }

    public Currency(float rate) {
        this.rate = rate;
    }

    public void convert() {
        this.result = this.rate * this.input;
    }

    public float getInput() {
        return input;
    }
    public void setInput(float input) {
        this.input = input;
    }
    public float getResult() {
        return result;
    }
    public void setResult(float result) {
        this.result = result;
    }
    public float getRate() {
        return rate;
    }
    public void setRate(float rate) {
        this.rate = rate;
    }

}
