#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG_MSG "The private language argument is a family of considerations, developed by Ludwig Wittgenstein in Philosophical Investigations (PI), \
aiming to show that a language whose expressions are, in principle, understandable by only a single individual is unintelligible."

# define INFO_MSG "Wittgenstein imagines keeping a diary: whenever a certain recurring sensation occurs, the subject writes 'S.' \
Could the subject have defined S by privately 'pointing' (attending) to the sensation and associating the mark with it? He argues that:\
- If S just means 'whatever I now feel,' then 'whatever seems right to me is right,' and the contrast between correct and incorrect use collapses—so there is no rule to follow.\
- If S is supposed to mean 'the same sensation as before,' appeal to 'remembering the connection correctly' presupposes that there was a determinate earlier correlation—precisely what is at issue in a purely private setting."

# define WARNING_MSG "[the fact, ndr] That there is no criterion of correctness in the diary case has an important consequence. \
Since there is no way for the diarist to identify later sensations as S or not as S, it is faulty to talk about recording the recurrence of a certain sensation."

# define ERROR_MSG "'I have plunged into the water of doubt, again.' - L. Wittgenstein"

class	Harl {
	private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

	public:
	Harl();
	~Harl();
	void	complain( std::string level );
};

typedef void	(Harl::*t_complains)( void );
typedef struct s_make_complains
{
	std::string	level;
	t_complains	funct;
}	t_make_complains;


#endif