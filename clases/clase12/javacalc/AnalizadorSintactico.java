import java.io.Reader;
import java.io.IOException;

public class AnalizadorSintactico {

    private AnalizadorLexico anlex;
    
    public AnalizadorSintactico(Reader entrada)  {
	anlex = new AnalizadorLexico(entrada);
    }

    public Arbol parser()
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
	
	return prog();
    }

    public Arbol prog()  
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
	Arbol expr = expr();

	Lexema lexema = anlex.obtLexema();

	if (lexema.obtTipo() != TipoLexema.EOF) {
	    System.err.println("Error Sintactico");
	    throw new AnalizadorSintacticoExcepcion();
	}

	return expr;
    }

    public Arbol expr() 
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
	return expr1(term());
    }

    public Arbol expr1(Arbol izq) 
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
	Lexema lexema = anlex.obtLexema();

	if (lexema.obtTipo() == TipoLexema.SUMA) {
	    return expr1(new Suma(izq, term()));
	}
	else if (lexema.obtTipo() == TipoLexema.RESTA) {
	    return expr1(new Resta(izq, term()));
	}

	anlex.retornarLexema();

	return izq;
    }

    public Arbol term() 
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
	return term1(negacion());
    }

    public Arbol term1(Arbol izq) 
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
		Lexema lexema = anlex.obtLexema();

	if (lexema.obtTipo() == TipoLexema.MULTIPLICACION) {
	    return term1(new Multiplicacion(izq, negacion()));
	}
	else if (lexema.obtTipo() == TipoLexema.DIVISION) {
	    return term1(new Division(izq, negacion()));
	}

	anlex.retornarLexema();
	
	return izq;
    }
    
    public Arbol negacion()  
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {
	Lexema lexema = anlex.obtLexema();

	if (lexema.obtTipo() == TipoLexema.RESTA) {
	    return new MenosUnario(factor());
	}

	anlex.retornarLexema();

	return factor();
    }

    public Arbol factor()  
	throws IOException,
	       AnalizadorLexicoExcepcion,
	       AnalizadorSintacticoExcepcion {

	Lexema lexema = anlex.obtLexema();

	if (lexema.obtTipo() == TipoLexema.NUMERO) {
	    return new Numero(((LiteralLexema) lexema).obtValor());
	}

	if (lexema.obtTipo() == TipoLexema.ABREPARENTESIS) {
	    Arbol resultado = expr();
	    lexema = anlex.obtLexema();
	    if (lexema.obtTipo() == TipoLexema.CIERRAPARENTESIS) {
		return resultado;
	    }
	    else {
		System.out.println("Experado )");
		throw new AnalizadorSintacticoExcepcion();
	    }
	}

	System.out.println("Se experaba (, Numero");
	throw new AnalizadorSintacticoExcepcion();
    }
}
