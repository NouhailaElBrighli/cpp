/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-brig <nel-brig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:58:17 by nel-brig          #+#    #+#             */
/*   Updated: 2023/01/17 23:17:23 by nel-brig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap nouha("nouha");
	//if it has not a name

	nouha.attack("khaoula");
	// nouha.Print_attributes();
	nouha.beRepaired(5);
	// nouha.Print_attributes();
	nouha.takeDamage(15);
	// nouha.Print_attributes();
	nouha.attack("khoula");
	// nouha.Print_attributes();
	nouha.beRepaired(5);
	// nouha.beRepaired(1);
}