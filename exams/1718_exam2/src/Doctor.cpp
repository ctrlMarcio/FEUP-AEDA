/*
 * Doctor.cpp
 */

#include "Doctor.h"


Patient::Patient(unsigned codP, string mS) : codeP(codP), medicalSpecialty(mS) {}

string Patient::getMedicalSpecialty() const {
	return medicalSpecialty;
}

unsigned Patient::getCode() const {
	return codeP;
}

Doctor::Doctor(unsigned codM, string mS) : codeM(codM), medicalSpecialty(mS) {}


Doctor::Doctor(unsigned codM, string mS, queue<Patient> patients1) : codeM(codM), medicalSpecialty(mS), patients(patients1) {}

unsigned Doctor::getCode() const {
	return codeM;
}

string Doctor::getMedicalSpecialty() const {
	return medicalSpecialty;
}

queue<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient &p1) {
	patients.push(p1);
}

Patient Doctor::removeNextPatient() {
	if (!patients.empty()) {
		Patient p1 = patients.front();
		patients.pop();
		return p1;
	} else throw PatientInexistent();
}


void Doctor::moveToFront(unsigned codP1) {
	queue<Patient> aux;
	queue<Patient> final;

	while (patients.front().getCode() != codP1 && !patients.empty()) {
		aux.push(patients.front());
		patients.pop();
	}

	if (patients.empty()) {
		patients = aux;
		return;
	}

	final.push(patients.front());
	patients.pop();

	while (!aux.empty()) {
		final.push(aux.front());
		aux.pop();
	}

	while (!patients.empty()) {
		final.push(patients.front());
		patients.pop();
	}

	this->patients = final;
}

