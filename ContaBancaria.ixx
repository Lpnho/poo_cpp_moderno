export module ContaBancaria;
import <string>;
import Cliente;

export class ContaBancaria {
private:
	Cliente _cliente;
	std::string _numero_conta;
	double _saldo;
public:
	//ContaBancaria() = default;
	ContaBancaria(Cliente cliente, std::string numero_conta,double saldo_inicial=0):
		_cliente(std::move(cliente)), _numero_conta(std::move(numero_conta)), _saldo{saldo_inicial} {}

	Cliente const& cliente() const { return _cliente; }
	double saldo() const { return _saldo; }
	std::string const& numero_conta() { return _numero_conta; }
	bool sacar(double valor_saque);
	ContaBancaria& depositar(double valor_deposito);
	//friend std::ostream& operator<<(std::ostream& cout, ContaBancaria const& conta);
};

bool ContaBancaria::sacar(double valor_saque)
{
	if (_saldo >= valor_saque)
	{
		_saldo -= valor_saque;
		return true;
	}
	return false;
}

ContaBancaria& ContaBancaria::depositar(double valor_deposito)
{
	_saldo += valor_deposito;
	return (*this);
}

//std::ostream& operator<<(std::ostream& cout, ContaBancaria const& conta) {
//	std::cout << conta._cliente
//		<< "\nNumero conta: " << conta._numero_conta
//		<< "\nSaldo: " << conta._saldo << '\n';
//	return cout;
//}