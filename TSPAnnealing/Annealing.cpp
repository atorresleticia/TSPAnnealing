#include "stdafx.h"
#include "Annealing.h"

individuo solucao_nova;
individuo solucao_atual;

cidade cidade_1;
cidade cidade_2;

populacao annealing::evolucao(populacao p)
{
	double ls = 600;
	double li = 25;
	double const_r = 0.9;

	double t = ls;
	double t_min = li;

	populacao nova_p = populacao();

	while (t > t_min)
	{
		for (auto i = 0; i < p.get_tamanho_populacao(); i++)
		{
			int tamanho = p.get_individuo_em(i).get_tamanho_rota();

			solucao_atual = p.get_individuo_em(i);
			solucao_nova = p.get_individuo_em(i);

			int index1 = rand() % tamanho;
			int index2 = rand() % tamanho;

			cidade_1 = solucao_nova.cidade(index1);
			cidade_2 = solucao_nova.cidade(index2);

			solucao_nova.set_cidade(index2, cidade_1);
			solucao_nova.set_cidade(index1, cidade_2);

			double delta = solucao_nova.distancia() - solucao_atual.distancia();
			
			if (delta < 0)
			{
				nova_p.armazena_individuo(solucao_nova);
			}
			else
			{
				double rnd = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				if (rnd < exp(-delta / t))
				{
					nova_p.armazena_individuo(solucao_nova);
				}
				else
				{
					nova_p.armazena_individuo(solucao_atual);
				}
			}

		}
		t *= const_r;
	}

	return nova_p;
}