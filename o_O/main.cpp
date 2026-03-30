void merge_sort(Dados* d, int ini, int fim){
    int meio;
    int idx_aux, idx_esq, idx_dir;
    Dados* aux;

    if (ini < fim){
        meio = (ini + fim)/2;

        merge_sort(d, ini, meio);
        merge_sort(d, meio+1, fim);

        idx_esq = ini;
        idx_dir = meio+1;
        idx_aux = 0;
        aux = (Dados *) malloc(sizeof(Dados) * (fim - ini + 1));

        while (idx_esq <= meio || idx_dir <= fim){
            if (idx_esq > meio){
                aux[idx_aux] = d[idx_dir];
                idx_dir++; 
            }
            else{
                if (idx_dir > fim){
                    aux[idx_aux] = d[idx_esq];
                    idx_esq++;
                }
                else{
                    if (d[idx_esq].valor < d[idx_dir].valor){
                        aux[idx_aux] = d[idx_esq];
                        idx_esq++;
                    }
                    else{
                        aux[idx_aux] = d[idx_dir];
                        idx_dir++;
                    }
                }
            }
            idx_aux++;
        }

        for(idx_aux = ini; idx_aux <= fim; idx_aux++){
            d[idx_aux].valor = aux[idx_aux - ini].valor;
            d[idx_aux].ordem = aux[idx_aux - ini].ordem;
        }

        free(aux);
    }
}

void merge_min(Dados *d, int ini, int fim) {
    Dados aux;
    int meio;

    if (ini < fim) {
        meio = (ini + fim) / 2;

        merge_min(d, ini, meio);
        merge_min(d, meio+1, fim);

        if (d[meio+1].valor < d[ini].valor) {
            aux = d[ini];
            d[ini] = d[meio+1];
            d[meio+1] = aux;
        }
    }
}
