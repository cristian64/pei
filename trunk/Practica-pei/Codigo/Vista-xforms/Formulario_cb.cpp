#include "Formulario.h"
#include <stdlib.h>

int operando = -1; // almacena el primer operando (cuando se pulsa el =)
int operador = -1; // indica el operador 1+ 2- 3* 4/
int reemplazar = 0; // actua como booleano, para saber si el reemplazar numero limpia la pantalla "lcd"

int memoria[10]; // almacena un valor auxiliar de memoria
int esperando_almacenar = 0;
int esperando_recuperar = 0;

FL_OBJECT *button_min;
FL_OBJECT *button_mr;

void almacenar(FL_OBJECT *label, int casilla)
{
    memoria[casilla] = atoi(fl_get_object_label(label));
    fl_set_object_color(button_min, 11, 0);
}

void recuperar(FL_OBJECT *label, int casilla)
{
    char new_text[500];
    sprintf(new_text, "%d", memoria[casilla]);
    fl_set_object_label(label, new_text);
    reemplazar = 0;
    fl_set_object_color(button_mr, 11, 0);
}


void add_number(FL_OBJECT *label, int n)
{
    const char *text = fl_get_object_label(label);
    char new_text[500];

    if (text[0] != '0' && reemplazar == 0)
        sprintf(new_text, "%s%d", text, n);
    else
    {
        sprintf(new_text, "%d", n);
        reemplazar = 0;
    }

    fl_set_object_label(label, new_text);
}

void clear(FL_OBJECT *label)
{
    char new_text[500];
    new_text[0] = '0';
    new_text[1] = '\0';
    fl_set_object_label(label, new_text);
    
    operando = -1;
    operador = -1;
    reemplazar = 0;
}

int is_number(char c)
{
    return '0' <= c && c <= '9';    
}

void c(FL_OBJECT *label)
{
    const char *text = fl_get_object_label(label);
    char new_text[500];
    
    // Deletes last number (only if there is more than one number).
    strcpy(new_text, text);
    
    int length = strlen(new_text);
    int lastNumberIndex = -1;
    int previousLastNumberIndex = -1;
    
    int i;
    for (i = 0; i < length; i++)
    {
        if (is_number(new_text[i]))
        {
            previousLastNumberIndex = lastNumberIndex;
            lastNumberIndex = i;
        }
    }
    
    if (lastNumberIndex != -1 && previousLastNumberIndex != -1)
    {
        new_text[lastNumberIndex] = '\0';
        fl_set_object_label(label, new_text);
    }
    else
    {
        clear(label);
    }
}

void sign(FL_OBJECT *label)
{
    const char *text = fl_get_object_label(label);
    char new_text[500];
    
    int length = strlen(text);
    int i;
    strcpy(new_text, text);
    
    if (new_text[0] != '-')
    {
        if (new_text[0] != '0')
        {
            for (i = length; i > 0; i--)
            {
                new_text[i] = new_text[i - 1];
            }
            new_text[0] = '-';
            new_text[length + 1] = '\0';
        }
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            new_text[i] = new_text[i + 1];
        }
        new_text[length - 1] = '\0';
    }
    
    fl_set_object_label(label, new_text);
}


/* Callbacks and freeobj handles for form Calculadora */

/***************************************
 ***************************************/

void button_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar == 1)
    {
        almacenar((FL_OBJECT *) ob->u_vdata, data);
        esperando_almacenar = 0;
    }
    else if (esperando_recuperar == 1)
    {
        recuperar((FL_OBJECT *)ob->u_vdata, data);
        esperando_recuperar = 0;
    }
    else
    {
        add_number((FL_OBJECT *)ob->u_vdata, data);
    }
}


/***************************************
 ***************************************/

void button_plus_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
    {
        reemplazar = 1;
        operador = 1;
        operando = atoi(fl_get_object_label((FL_OBJECT *)ob->u_vdata));
    }
}

/***************************************
 ***************************************/

void button_minus_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
    {
        reemplazar = 1;
        operador = 2;
        operando = atoi(fl_get_object_label((FL_OBJECT *)ob->u_vdata));
    }
}


/***************************************
 ***************************************/

void button_div_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
    {
        reemplazar = 1;
        operador = 4;
        operando = atoi(fl_get_object_label((FL_OBJECT *)ob->u_vdata));
    }
}


/***************************************
 ***************************************/

void button_equal_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
    {
        if (reemplazar != 1)
        {
            const char *text = fl_get_object_label((FL_OBJECT *)ob->u_vdata);
            int actual = atoi(text);
            int resultado = actual;
            
            switch (operador)
            {
                case 1:
                    resultado = operando + actual;
                    break;
                    
                case 2:
                    resultado = operando - actual;
                    break;
                    
                case 3:
                    resultado = operando * actual;
                    break;
                    
                case 4:
                    resultado = (actual != 0) ? operando / actual : 99999999;
                    break;
                    
                default:
                    break;
            }
            operador = -1;
            
            char new_text[500];
            sprintf(new_text, "%d", resultado);
            fl_set_object_label((FL_OBJECT *)ob->u_vdata, new_text);
            reemplazar = 1;
        }
    }
}


/***************************************
 ***************************************/

void button_mult_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
    {
        reemplazar = 1;
        operador = 3;
        operando = atoi(fl_get_object_label((FL_OBJECT *)ob->u_vdata));
    }
}


/***************************************
 ***************************************/

void button_c_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
        c((FL_OBJECT *)ob->u_vdata);
}


/***************************************
 ***************************************/

void button_clr_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
        clear((FL_OBJECT *)ob->u_vdata);
}


/***************************************
 ***************************************/

void button_min_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_recuperar == 0)
    {
        esperando_almacenar = 1;
        fl_set_object_color(ob, 6, 0);
        button_min = ob;
    }
}


/***************************************
 ***************************************/

void button_mr_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar == 0)
    {
        esperando_recuperar = 1;
        fl_set_object_color(ob, 6, 0);
        button_mr = ob;
    }
}


/***************************************
 ***************************************/

void button_sign_cb( FL_OBJECT * ob,
         long        data )
{
    if (esperando_almacenar + esperando_recuperar == 0)
        sign((FL_OBJECT *)ob->u_vdata);
}






