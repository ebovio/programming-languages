public abstract class NodoUnario extends Arbol {

    private Arbol hijo;
    
    public NodoUnario(Arbol hijo) {
	this.hijo = hijo;
    }

    public Arbol obtHijo() {
	return hijo;
    }
}
