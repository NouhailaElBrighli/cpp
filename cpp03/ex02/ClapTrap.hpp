/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <nel-brig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:56:37 by nel-brig          #+#    #+#             */
/*   Updated: 2023/01/18 04:08:03 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;
	public :
		ClapTrap();
		ClapTrap(ClapTrap& obj);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap& obj);
		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		// void Print_attributes();
};


#endif