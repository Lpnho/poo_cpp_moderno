export module Cliente;
import <string>;

export class Cliente{
private:
	std::string _nome;
	std::string _cpf;
	std::uint8_t _idade;
public:
	Cliente(std::string nome, std::string cpf,std::uint8_t idade):
		_nome(std::move(nome)), _cpf(std::move(cpf)), _idade{idade} {}

	std::string const& nome() const { return _nome; }
	std::string const& cpf() const { return _cpf; }
	std::uint8_t idade() const { return _idade; }
	//friend std::ostream& operator<< (std::ostream& cout, const Cliente& cliente);
};

//std::ostream& operator<<(std::ostream& cout, const Cliente& cliente)
//{
//	std::cout << "\nNome do Cliente: " << cliente._nome
//		<< "\nCPF: " << cliente._cpf
//		<< "\nidade: " << (int)cliente._idade << '\n';
//	return cout;
//}
