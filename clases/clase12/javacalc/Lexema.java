public class Lexema {

    private TipoLexema tipo;
    private int linea, columna;

    public Lexema() {
	this.tipo = TipoLexema.EOF;
	this.linea = 0;
	this.columna = 0;
    }

    public Lexema(TipoLexema tipo, int linea, int columna) {
	this.tipo = tipo;
	this.linea = linea;
	this.columna = columna;
    }

    public TipoLexema obtTipo() {
	return tipo;
    }

    public int obtLinea() {
	return linea;
    }

    public int obtColumna() {
	return columna;
    }
}
