import java.io.Reader;
import java.io.IOException;

public class AnalizadorLexico {
    
    private Reader entrada;
    private int linea;
    private int columna;
    private boolean requiereLexema;
    private Lexema anteriorLexema;
    
    public AnalizadorLexico(Reader entrada) {
	
	this.entrada = entrada;
	this.linea = 0;
	this.columna = 0;
	this.anteriorLexema = null;
	this.requiereLexema = false; 
    }

    public Lexema obtLexema()
	throws IOException, AnalizadorLexicoExcepcion {

	if (! requiereLexema) {
	    requiereLexema = true;
	    return anteriorLexema;
	}

	Lexema t = null;
	int estado = 0;
	boolean encontrado = false;
	int c;
	StringBuffer sb = new StringBuffer();
	int k;
	int clinea, ccolumn;
	TipoLexema tipo = TipoLexema.DESCONOCIDO;
	entrada.mark(1);
	c = entrada.read();

	while (!encontrado) {
	    columna++;
	    switch (estado) {
	    case 0:
		ccolumn = columna;
		clinea = linea;

		if (Character.isDigit(c)) estado = 1;
		else if (c == '+') estado = 2;
		else if (c == '-') estado = 3;
		else if (c == '*') estado = 4;
		else if (c == '/') estado = 5;
		else if (c == '(') estado = 6;
		else if (c == ')') estado = 7;
		else if (c == '\n') {
		    columna=-1;
		    linea++;
		}
		else if (Character.isWhitespace(c)) {
		}
		else if (c == -1) {
		    encontrado = true;
		    tipo = TipoLexema.EOF;
		}
		else {
		    System.err.println("Lexema no reconocido en la linea: " +
				       linea + " columna: " + columna +
				       " caracter: " + c);
		    throw new AnalizadorLexicoExcepcion();
		}
		break;
	    case 1:
		if (Character.isDigit(c)) estado = 2;
		else {
		    tipo = TipoLexema.NUMERO;
		    encontrado = true;
		}
		break;

	    case 2:
		tipo = TipoLexema.SUMA;
		encontrado = true;
		break;

	    case 3:
		tipo = TipoLexema.RESTA;
		encontrado = true;
		break;

	    case 4:
		tipo = TipoLexema.MULTIPLICACION;
		encontrado = true;
		break;
		
	    case 5:
		tipo = TipoLexema.DIVISION;
		encontrado = true;
		break;

	    case 6:
		tipo = TipoLexema.ABREPARENTESIS;
		encontrado = true;
		break;

	    case 7:
		tipo = TipoLexema.CIERRAPARENTESIS;
		encontrado = true;
		break;
		
	    }

	    if (!encontrado) {
		sb.append(c);
		entrada.mark(1);
		c = entrada.read();
	    }
	}

	entrada.reset();
	columna--;

	if (tipo == TipoLexema.NUMERO) {
	    t = new LiteralLexema(tipo,
				  Integer.parseInt(sb.toString()),
				  linea,
				  columna);
	}
	else {
	    t = new Lexema(tipo, linea, columna);
	}

	anteriorLexema = t;
	return t;
    }
    
    public void retornarLexema() {
	requiereLexema = false;
    }
}
