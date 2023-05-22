export module Banco;

import <string>;
import <map>;
import <optional>;
import Cliente;
import ContaBancaria;

export class Banco {
private:
	std::string _nome;
	std::uint64_t _agencia;
	std::uint64_t _numero_cliente;
	std::map<std::string, ContaBancaria> _clientes;
public:
	Banco(std::string nome, std::uint64_t agencia = 0) :
		_nome(std::move(nome)), _agencia{ agencia }, _numero_cliente{0} {}

	std::string const& nome() const { return _nome; }
	std::uint64_t agencia() const { return _agencia; }
	std::uint64_t numero_cliente() const { return _numero_cliente; }
	std::map<std::string, ContaBancaria>& clientes() { return _clientes; }
	std::optional<ContaBancaria> abrir_conta(std::string nome, std::string cpf, std::uint8_t idade,double saldo_inicial=0);
	bool fechar_conta(std::string const& numero_conta);
	std::optional<ContaBancaria> obter_conta(std::string const& numero_conta);
};

std::optional<ContaBancaria> Banco::abrir_conta(std::string nome, std::string cpf, std::uint8_t idade,double saldo_inicial)
{
	if(idade>=18)
	{
		std::string numero_conta = (std::to_string(_agencia) + std::to_string(_numero_cliente));
		ContaBancaria conta_bancaria(Cliente(std::move(nome), std::move(cpf), idade),numero_conta,saldo_inicial);
		_clientes.insert(std::make_pair(numero_conta,conta_bancaria));
		++_numero_cliente;
		return conta_bancaria;
	}
	return std::nullopt;
}

std::optional<ContaBancaria> Banco::obter_conta(std::string const& numero_conta)
{
	std::map<std::string, ContaBancaria>::iterator iterator = _clientes.find(numero_conta);
	if (iterator == _clientes.end())
		return std::nullopt;
	return (*iterator).second;
}

bool Banco::fechar_conta(const std::string& numero_conta)
{
	return (_clientes.erase(numero_conta));
}
