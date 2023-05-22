#include <iostream>
import Cliente;
import ContaBancaria;
import Banco;

int main()
{
	Banco banco_do_brasil("Brasil",83);
	std::optional<ContaBancaria> conta = banco_do_brasil.abrir_conta("Luiz Felipe", "11234234", 18,200);
	/*if (conta) 
	{
		ContaBancaria conta_luiz = conta.value();
		conta_luiz.depositar(1000).sacar(10);
		conta_luiz.sacar(100);
		
		std::cout << "Numero conta: "<< conta_luiz.numero_conta()
			<<"\nSaldo: "<<conta_luiz.saldo()<<'\n';
	}*/
	std::cout << "Banco: "<<banco_do_brasil.nome()
			  << "\nAgencia: " << banco_do_brasil.agencia();
	for (auto& [numero_conta, cliente]  : banco_do_brasil.clientes())
	{
		std::cout << "\nNome do Cliente: " << cliente.cliente().nome()
			<< "\nCPF: " << cliente.cliente().cpf()
			<< "\nidade: " << (int)cliente.cliente().idade()
			<< "\nNumero conta: " << cliente.numero_conta()
			<< "\nSaldo: " << cliente.saldo() << '\n';
	}
	return 0;
}