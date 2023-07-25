#include "deck.h"

int _comparestr(const char *str1, const char *str2);
char getcardIN(deck_node_t *card);
void sort_type(deck_node_t **deck);
void sort_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _comparestr - a function that ompares two strings.
 * @str1: the first string to compare
 * @str2: The second string to be compare.
 * Return: 0 (Success) if the strings are equal
 */
int _comparestr(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * getcardIN - to get the integer value of a card.
 * @card: the card to get the integer value
 * Return: The integer value.
 */
char getcardIN(deck_node_t *card)
{
	if (_comparestr(card->card->value, "Ace") == 0)
		return (0);
	if (_comparestr(card->card->value, "1") == 0)
		return (1);
	if (_comparestr(card->card->value, "2") == 0)
		return (2);
	if (_comparestr(card->card->value, "3") == 0)
		return (3);
	if (_comparestr(card->card->value, "4") == 0)
		return (4);
	if (_comparestr(card->card->value, "5") == 0)
		return (5);
	if (_comparestr(card->card->value, "6") == 0)
		return (6);
	if (_comparestr(card->card->value, "7") == 0)
		return (7);
	if (_comparestr(card->card->value, "8") == 0)
		return (8);
	if (_comparestr(card->card->value, "9") == 0)
		return (9);
	if (_comparestr(card->card->value, "10") == 0)
		return (10);
	if (_comparestr(card->card->value, "Jack") == 0)
		return (11);
	if (_comparestr(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_type - Sorts the deck card types
 * @deck: a pointer to the deck
 */
void sort_type(deck_node_t **deck)
{
	deck_node_t *x, *y, *z;

	for (x = (*deck)->next; x != NULL; x = z)
	{
		z = x->next;
		y = x->prev;
		while (y != NULL && y->card->kind > x->card->kind)
		{
			y->next = x->next;
			if (x->next != NULL)
				x->next->prev = y;
			x->prev = y->prev;
			x->next = y;
			if (y->prev != NULL)
				y->prev->next = x;
			else
				*deck = x;
			y->prev = x;
			y = x->prev;
		}
	}
}

/**
 * sort_value - Sorts the deck card values
 * @deck: a pointer to the deck
 */
void sort_value(deck_node_t **deck)
{
	deck_node_t *x, *y, *z;

	for (x = (*deck)->next; x != NULL; x = z)
	{
		z = x->next;
		y = x->prev;
		while (y != NULL &&
		       y->card->kind == x->card->kind &&
		       getcardIN(y) > getcardIN(x))
		{
			y->next = x->next;
			if (x->next != NULL)
				x->next->prev = y;
			x->prev = y->prev;
			x->next = y;
			if (y->prev != NULL)
				y->prev->next = x;
			else
				*deck = x;
			y->prev = x;
			y = x->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: a pointer to the deck
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_type(deck);
	sort_value(deck);
}
