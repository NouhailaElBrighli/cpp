/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <nel-brig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:56:26 by nel-brig          #+#    #+#             */
/*   Updated: 2023/01/18 04:32:35 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/***************************************************/

// void ClapTrap::Print_attributes()
// {
// 	std::cout << "***********************************" << std::endl;
// 	std::cout << "name == " << name << std::endl;
// 	std::cout << "hit points == " << HitPoints << std::endl;
// 	std::cout << "Energy points == " << EnergyPoints << std::endl;
// 	std::cout << "attack damage == " << AttackDamage << std::endl;
// 	std::cout << "***********************************" << std::endl;
// }

/***********************************************/

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << "\033[1;35m" << "Claptrap " << this->name << " constructor called\033[1;30m" << std::endl;
}

ClapTrap::~ClapTrap()
{
	if (name.length() == 0)
		std::cout << "\033[1;35m" << "Claptrap destructor called" << std::endl;
	else
		std::cout << "\033[1;35m" << "Claptrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints == 0 || this->HitPoints == 0)
	{
		if (name.length() == 0)
			std::cout << "\033[1;31m" << "he is already dead\033[1;30m" << std::endl;
		else
			std::cout << "\033[1;31m" << name << " is already dead\033[1;30m" << std::endl;
		return;
	}
	this->EnergyPoints--;
	if (name.length() == 0)
		std::cout << "\033[1;32mClipTrap attacks "  << target << " " << "causing " << AttackDamage << " point of damage\033[1;30m" << std::endl;
	else
		std::cout << "\033[1;32mClipTrap "  << name << " attacks "  << target << " " << "causing " << AttackDamage << " point of damage\033[1;30m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints == 0 || this->HitPoints == 0)
	{
		if (name.length() == 0)
			std::cout << "\033[1;31m" << "he is already dead\033[1;30m" << std::endl;
		else
			std::cout << "\033[1;31m" << name << " is already dead\033[1;30m" << std::endl;
		return;
	}
	this->EnergyPoints--;
	this->HitPoints += amount;
	if (name.length() == 0)
		std::cout << "\033[1;34mhe repairs itself with " << amount << " of points\033[1;30m" << std::endl;
	else
		std::cout << "\033[1;34m" << name << " repairs itself with " << amount << " of points\033[1;30m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->EnergyPoints == 0 || this->HitPoints == 0)
	{
		if (name.length() == 0)
			std::cout << "\033[1;31m" << "he is already dead\033[1;30m" << std::endl;
		else
			std::cout << "\033[1;31m" << name << " is already dead\033[1;30m" << std::endl;
		return;
	}
	this->HitPoints -= amount;
	if (this->HitPoints <= -1)
		this->HitPoints = 0;
	if(name.length() == 0)
		std::cout << "\033[1;33m" << "he take damage and lost "  << amount << " of hit points \033[1;30m" << std::endl;
	else
		std::cout << "\033[1;33m" << name << " take damage and lost "  << amount << " of hit points \033[1;30m" << std::endl;		 
}

ClapTrap::ClapTrap()
{
	std::cout << "\033[1;35mClaptrap Default Constructor called\033[1;30m" << std::endl;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;	
}

ClapTrap::ClapTrap(ClapTrap& obj)
{
	std::cout << "Copy constrcted called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(ClapTrap& obj)
{
	std::cout << "Copy assignement called" << std::endl;
	this->name = obj.name;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	return (*this);
}

