/*******Templates******/

template< typename _Type, size_t _Len > 
  class GenericArray{
    public:
      enum{ 
        Length 	= _Len,
        Size 	= sizeof( _Type ) * _Len,
      };
      _Type& operator[]( uint16_t i_Index ) { return this->t_Data[ i_Index ]; }
      operator _Type*(){ return this->t_Data; }
				
      _Type t_Data[ Length ];
};


/*******Utilities********/

template<typename T, int _Length> void forEach(GenericArray<T, _Length> objs, void (*action)(T));

template<typename T, int _Length> void forEach(GenericArray<T, _Length> objs, void (*action)(T))
{
    for(int i = 0; i< _Length; i++)
    {
        action(objs[i]);
    }
}

template<typename T, int _Length> void skip(GenericArray<T, _Length> objs, int skip, void (*action)(T));

template<typename T, int _Length> void skip(GenericArray<T, _Length> objs, int skip, void (*action)(T))
{
    for(int i = skip - 1; i< _Length; i++)
    {
        action(objs[i]);
    }
}

template<typename T, int _Length> void take(GenericArray<T, _Length> objs, int take, void (*action)(T));

template<typename T, int _Length> void take(GenericArray<T, _Length> objs, int take, void (*action)(T))
{
    for(int i = 0; i< (take - 1); i++)
    {
        action(objs[i]);
    }
}

/*******Objects*********/

class PIN{
    protected:
        int pin;
    
    public:
        PIN(int p){
            pin = p;
        }
};


class LED : public PIN{
    public:
        int toggleDelay; 
        LED(int p) : PIN(p){
            pinMode(p, 1); //1 = OUTPUT VALUE
            pin = p;
        }

        void toggle(void){
            digitalWrite(pin, !digitalRead(pin));
            delay(toggleDelay);
        }

        void on(void)
        {
            digitalWrite(pin, 1);
        }

        void off(void){
            digitalWrite(pin, 0);
        }
};


class BUTTON : public PIN{
    public:
        int state;

        BUTTON(int p) : PIN(p){

        }

        void updateState(void){
            state = digitalRead(pin);
        }

        bool isPressed(bool withUpdate)
        {
            if(withUpdate)
            {
                updateState();
            }

            return state == 1;
        }
};