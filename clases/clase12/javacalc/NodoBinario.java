public abstract class NodoBinario extends Arbol {

    private Arbol hijoIzq;
    private Arbol hijoDer;

    public NodoBinario(Arbol hijoIzq, Arbol hijoDer) {
	this.hijoIzq = hijoIzq;
	this.hijoDer = hijoDer;
    }

    public Arbol obtHijoIzq() {
	return hijoIzq;
    }

    public Arbol obtHijoDer() {
	return hijoDer;
    }
}
