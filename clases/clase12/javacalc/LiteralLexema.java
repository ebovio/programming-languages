public class LiteralLexema extends Lexema {

    private int valor;
    
    public LiteralLexema(TipoLexema tipo, int valor, int linea, int columna) {
	super(tipo, linea, columna);

	this.valor = valor;
    }

    public int obtValor() {
	return valor;
    }
}
