#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    { // i = quem vota

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        { // j = em que votou para a posição j (1, 2 ,3...)
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name)) // chama a funcao passando quem votou, qual posição do candidato e o nome
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // checar se o nome é valido ( linear search )
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcasecmp(candidates[i].name, name))
        {
            // atualizar array passando [voter][rank] = index do candidato
            preferences[voter][rank] = i;
            return 1;
            // retorna true
        }
    }
    // se o nome não é valido retorna false
    return 0;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // loop:
    // find votes on the array using i ( voters ) and j ( candidates position )
    // array[i][j] = index of the candidate voted
    for (int i = 0; i < voter_count; i++)
    {
        // loop:
        // if a candidate index on j position was not eliminated
        // count vote for candidate
        // else: check if a candidate on next position was eliminated and count vote
        // update votes in the struct
        for (int j = 0; j < candidate_count; j++)
        {
            int voter_option = preferences[i][j];
            if (candidates[voter_option].eliminated == false)
            {
                candidates[voter_option].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // If one candidate have more than the half of votes he is the winner, else, return false

    int half_votes = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > half_votes && !candidates[i].eliminated)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // loop:
    // Se o candidato não foi eliminado
    // salvar o numero de votos em uma variavel, se encontrar um menor, trocar
    // retornar menor valor
    // Se foi eliminado passar para o próximo
    int votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (i == 0)
        {
            votes = candidates[0].votes;
        }

        if (candidates[i].eliminated == false && candidates[i].votes < votes)
        {
            votes = candidates[i].votes;
        }
    }
    return votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // se tem um que não é o minimo então está empatado
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // se o candidato ainda não tiver sido eliminado e o numero de votos dele for o menor
    // eliminar das eleições

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
