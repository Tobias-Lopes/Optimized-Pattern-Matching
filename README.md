# Optimized-Pattern-Matching

Right at the beginning of the pandemic, two Brazilian scientists showed the world Brazil's scientific potential by sequencing the genome of the Coronavirus that appeared here just 48 hours after the confirmation of the first case of Covid in Brazil (at the time, a record). It is a sample of our capacity when there is investment in science.

Genome sequencing is essential to identify new variants, compared to the sequencing of other genomes. The comparison is then carried out using text pattern matching algorithms (also known as pattern matching or string-searching), since DNA can be represented by a sequence of characters, each representing one of its nitrogenous bases: adenine ( A), cytosine (C), guanine (G) or thymine (T).

However, carrying out a search without any optimization on a DNA sequence, which has millions of characters, can be very costly! So what to do to optimize?

There are several algorithms that optimize the search, usually pre-processing the pattern or text first. For now, let's explore a simple idea, but one that can tremendously help our scientists in their search for patterns.

The idea is, before carrying out the search itself, to save information, for each character in the text, whether it is in the pattern or not. This would help the search "skip" comparisons when a character is not in the pattern. For example, if we have a text ACATACAGACAC and we are looking for the ACAC pattern. In an innocent search (without optimization), we would have the following displacement of the pattern in the search process over the text.

Text: A C A T A C G A C A C
Pattern: A C A C (compares A with A, then C with C, then A with A, then C with T. Not matched! C is different from T)
          A (compares A with C. Not married. A is different from C)
            A C (compares A with A, then C with T. Not married. C is different from T)
              A (not married. A is different from T)
                A C A (not married. A is different from G)
                  A (not married. A is different from C)
                    A (not married. A is different from G)
                      A C A C (married!)

However, we can already know that T is not in the pattern and make a jump and start the search again right after T. The search with this new mechanism could be like this:
Text: A C A T A C G A C A C
Pattern: A C A C (compares A with A, then C with C, then A with A, then C with T. Not matched. C is different from T)
                (since there is no T in the pattern, we can skip it)
                A C A (not married. A is different from G)
                      (since there is no G in the pattern, we can skip it)
                      A C A C (married!)​

Help Brazilian science by implementing a pattern search on a text using the idea described above. Your program must read two lines of standard input. The first contains the text over which the pattern will be searched, while the second line contains the pattern. Your program must send the search process that occurred to standard output, presenting the character of the text being compared at each iteration and presenting the text "no" when the characters in the text and the pattern are different and the text "yes" when there is complete pattern matching.

The final line of the output informs whether there was no marriage ("I didn't find the pattern") or whether there was. In this case, it presents the index in the text where the marriage is found ("I found the pattern at index X").

Note: There are much more sophisticated pattern search algorithms than the idea presented here, but some of them use similar resources, such as the "last occurrence index" of the text characters in the pattern to perform the jumps.
