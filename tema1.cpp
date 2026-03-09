#include <iostream>
#include <vector>
#include <string>



class Statie {
private:
    std::string nume;
    int ordinePeLinie;
    int timpStationare;

public:
    Statie(const std::string& nume, int ordine, int timpStationare)
        : nume(nume),
          ordinePeLinie(ordine),
          timpStationare(timpStationare) {}

    friend std::ostream& operator<<(std::ostream& out, const Statie& s) {
        out << "Statie: " << s.nume
            << " | Ordine: " << s.ordinePeLinie
            << " | Timp stationare: " << s.timpStationare << " min";
        return out;
    }
};



class Linie {
private:
    std::string codLinie;
    std::string tipTransport;
    std::vector<Statie> statii;

public:
    Linie(const std::string& cod, const std::string& tip)
        : codLinie(cod), tipTransport(tip) {}

    void adaugaStatie(const Statie& s) {
        statii.push_back(s);
    }

    int numarStatii() const {
        return statii.size();
    }

    bool contineStatia(const std::string& nume) const {
        return false;
    }

    double timpTotalStationare() const {
        return 0.0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Linie& l) {
        out << "+ Linie: " << l.codLinie
            << " | Tip transport: " << l.tipTransport
            << "\n+ Statii:\n";

        for (const auto& s : l.statii){
            out << s << "\n";
        }

        return out;
    }
};



class MijlocTransport {
private:
    std::string linie;
    std::string idVehicul;
    int capacitate;
    double vitezaMedie;
    int numarStatii;

public:
    MijlocTransport(const std::string& linie,
                    const std::string& id,
                    int capacitate,
                    double viteza,
                    int nrStatii)
        : linie(linie),
          idVehicul(id),
          capacitate(capacitate),
          vitezaMedie(viteza),
          numarStatii(nrStatii) {}

    // constructor de copiere
    MijlocTransport(const MijlocTransport& other)
        : linie(other.linie),
          idVehicul(other.idVehicul),
          capacitate(other.capacitate),
          vitezaMedie(other.vitezaMedie),
          numarStatii(other.numarStatii) {}

    // operator =
    MijlocTransport& operator=(const MijlocTransport& other) {
        if (this != &other) {
            linie = other.linie;
            idVehicul = other.idVehicul;
            capacitate = other.capacitate;
            vitezaMedie = other.vitezaMedie;
            numarStatii = other.numarStatii;
        }
        return *this;
    }

    // destructor
    ~MijlocTransport() {}

    double timpEstimativ() const {
        return 0.0;
    }

    bool esteRapid(double prag) const {
        return vitezaMedie > prag;
    }

    bool areCapacitateMinima(int prag) const {
        return capacitate >= prag;
    }

    friend std::ostream& operator<<(std::ostream& out, const MijlocTransport& m) {
        out << "Vehicul ID: " << m.idVehicul << "\n"
            << "Linie: " << m.linie << "\n"
            << "Capacitate: " << m.capacitate << "\n"
            << "Viteza medie: " << m.vitezaMedie << "\n"
            << "Numar statii: " << m.numarStatii << "\n";
        return out;
    }
};



class ReteaTransport {
private:
    std::vector<MijlocTransport> mijloace;
    std::vector<Linie> linii;

public:
    void adaugaMijloc(const MijlocTransport& m) {
        mijloace.push_back(m);
    }

    void adaugaLinie(const Linie& l) {
        linii.push_back(l);
    }

    void afiseazaVehiculePeLinie(const std::string& cod) const {

    }

    int capacitateTotalaLinie(const std::string& cod) const {
        return 0;
    }

    friend std::ostream& operator<<(std::ostream& out, const ReteaTransport& r) {
        out << " _______________ \n";
        out << "|RETEA TRANSPORT|\n\n";

        out << "-> Vehicule:\n";
        for (const auto& m : r.mijloace){
            out << m << "\n";
        }

        out << "\n-> Linii:\n";
        for (const auto& l : r.linii){
            out << l << "\n";
        }

        return out;
    }
};



int main() {

    Statie s1("Universitate", 1, 1);
    Statie s2("Romana", 2, 1);

    Linie linie336("336", "autobuz");
    linie336.adaugaStatie(s1);
    linie336.adaugaStatie(s2);

    MijlocTransport autobuz("336", "b_45", 80, 35.5, 14);

    ReteaTransport retea;
    retea.adaugaLinie(linie336);
    retea.adaugaMijloc(autobuz);

    std::cout << retea;

    return 0;
}
