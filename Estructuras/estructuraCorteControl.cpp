 while (i < cantidad)
    {
        string key = vector[i].ccampo;
        contador = 0;

        while (i < cantidad && key == vector[i].ccampo)
        {
            otroVector[i].campo = vector[i].campo;            
            
            i++;
        }
        
    }