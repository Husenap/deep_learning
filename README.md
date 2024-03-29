# Deep Learning

I started working on this project because I want to **Learn** more about Machine **Learn**ing 😉


## Simple Test

The goal of this test is to give the NN 4 numbers, and train it to return the first 2 numbers just to make sure the NN and math works. 

```c
Evaluating test data before training:
 Input:   1.0000        0   1.0000        0
Output:  -0.5628   1.0667

Training...

Evaluating test data after training:
 Input:   1.0000        0   1.0000        0
Output:   1.0000        0
```


## Handwritten digits

Here are some handwritten digits taken from the [MNIST database](http://yann.lecun.com/exdb/mnist/). There are `60000` digits for training and `10000` digits for testing.
I'm going to use these to write a neural network that uses hidden layers and backpropagation and learns how to determine what number is shown.

```
                        ;;--##@@@@@@**                                ##%%
                ;;;;;;%%@@@@@@@@@@@@%%--                          **@@@@--
            **##@@@@@@@@@@@@@@@@@@@@@@**                          %%@@@@--
            ==@@@@@@@@@@@@==**==**##@@@@**                        @@@@@@..
        **++@@@@@@@@@@@@--        %%@@@@**                        --@@@@++
    ..##@@@@@@@@@@##**        ..##@@@@@@                          %%@@@@**
    --@@@@@@@@@@@@@@++          --@@@@@@##                        @@@@@@;;
..##@@@@@@##**++++            --@@@@@@@@                      **@@@@==
##@@@@@@@@..  --              %%@@@@@@@@                      @@@@@@;;
@@@@@@@@**                ==##@@@@@@@@**                      @@@@@@
@@@@@@**              --##@@@@@@@@@@@@**                      %%@@@@++
@@@@@@@@..  ;;++++==@@@@@@@@@@@@@@==..                        @@@@@@;;
%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++                        **@@@@@@
    %%@@@@@@@@@@@@@@@@@@@@@@@@##++                        ##@@@@++
    --%%##@@@@@@@@@@@@@@@@%%**                            ;;@@@@@@..
            --##--%%##%%--;;                              %%@@@@++
                                                      ;;@@@@@@
                                                      ++@@@@##
                                                      ++@@@@**
                                                      ;;@@@@..

	..++@@##++                                 --@@@@==++++++;;..
	--##@@@@@@@@@@@@==..                       **@@@@@@@@@@@@@@@@++
	==@@@@@@@@@@@@@@@@%%                       ++@@@@@@@@@@@@@@@@==
	..++%%%%%%##@@@@@@@@;;                         ..----==%%%%@@@@@@**
				..%%@@@@%%                                     ==@@@@--
				;;@@@@@@;;                                 **@@@@@@
					%%@@@@++                           ;;==@@@@@@@@
					##@@@@++                       ;;@@@@@@@@@@@@@@--
			..**%%@@@@@@##..                       %%@@@@@@@@@@@@@@@@--
		==##@@@@@@@@@@@@@@@@**                     @@@@@@@@@@==@@@@@@@@
		%%@@@@@@@@@@@@@@@@@@@@@@;;                 ..%%%%;;      --@@@@**
	%%@@@@@@@@@@@@@@@@@@@@@@@@##..                                 ==@@==
	--@@@@@@##--##@@@@@@##%%@@@@@@**                               ++@@##
	==@@@@@@--  ##@@@@@@..;;@@@@@@%%       ..++==--;;              ++@@@@
	==@@@@==  --@@@@@@**      @@@@@@**     **@@@@@@@@++          ..@@@@%%
	==@@@@%%..##@@@@%%        ==@@@@@@     **@@@@@@@@==          %%@@@@--
	;;@@@@@@##@@@@@@--          %%@@@@.    ;;@@@@@@@@@@%%**--**##@@@@@@  .
	..@@@@@@@@@@@@%%            ..++==         **@@@@@@@@@@@@@@@@@@@@@@;;
	++@@@@@@@@@@                               ..++@@@@@@@@@@@@@@@@--
	..==@@@@%%                                         --==%%@@@@%%--

						%%@@..                                      ++==@@##
						++@@@@==                ........;;====@@@@@@@@@@@@
					;;@@@@@@++                  ==@@@@@@@@@@@@@@@@@@@@@@@@
					@@@@@@@@..                  ;;@@@@@@@@@@@@@@@@@@@@@@@@==
		..@@##    --@@@@@@**                    ++@@@@@@@@@@@@@@@@@@@@@@**
		##@@@@**  @@@@@@##                  ;;@@@@@@@@@@@@@@++;;
		--@@@@@@;;++@@@@@@--                %%@@@@@@==--
	..@@@@@@@@  @@@@@@##                    @@@@@@@@@@%%==;;
	**@@@@@@;;;;@@@@@@**----                %%@@@@@@@@@@@@@@##++
	@@@@@@++  ==@@@@@@##@@@@@@--            %%@@@@@@@@@@@@@@@@@@;;
	;;@@@@@@%%==@@@@@@@@@@@@@@@@==                  ****==@@@@@@@@@@
	..@@@@@@@@@@@@@@@@@@@@@@@@%%++                          ;;##@@%%
	--@@@@@@@@@@@@@@**--                ;;;;                    --@@%%
		****++@@@@@@**              ;;@@@@**                  ++@@@@
			..@@@@@@                --@@@@@@++;;              ##@@@@
			**@@@@@@                    @@@@@@@@@@++;;    ..++##@@@@;;
			**@@@@##                    ++@@@@@@@@@@@@@@@@@@@@@@@@@@
			##@@@@%%                    --@@@@@@@@@@@@@@@@@@@@@@++
			%%@@@@==                        ..==##@@@@@@@@@@@@@@##
			--@@%%--                            ..++@@##@@++;;

		..@@##                                   ......;;++++@@@@@@@@@@==--
		==@@@@==                             ;;%%@@@@@@@@@@@@@@@@@@@@@@@@##;;
		==@@@@@@@@..                         ##@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%
		@@@@@@@@@@;;                         %%@@@@@@@@@@@@@@##******##@@@@##
	**@@@@@@@@%%                             --------..            ##@@@@##
	==@@@@@@@@++                                                 **@@@@@@##
	**@@@@@@@@;;                                                 ;;@@@@@@@@**
	**@@@@@@@@..                                             **@@@@@@@@==
	==@@@@@@++                  ....                         ++@@@@@@@@@@..
--@@@@@@@@..      ;;--%%####%%@@##%%..                   ..==@@@@@@@@@@..
##@@@@@@%%      ==@@@@@@@@@@@@@@@@@@++..                 ++@@@@@@@@##..
@@@@@@@@==    %%@@@@@@@@@@@@@@@@@@@@@@**             **##@@@@@@@@@@
@@@@@@@@;;  %%@@@@@@@@@@@@####@@@@@@@@**         **@@@@@@@@@@%%..
@@@@@@@@..  ##@@@@##%%----....##@@@@@@**         **@@@@@@@@@@;;
@@@@@@@@**..##@@@@--    ..**##@@@@@@@@**     --@@@@@@@@@@%%
@@@@@@@@@@@@@@@@@@@@==%%@@@@@@@@@@@@@@**     ==@@@@@@@@@@..
==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==;;     %%@@@@@@@@@@**
	@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==   ..@@@@@@@@@@**
	;;==@@@@@@@@@@@@@@@@@@@@@@@@==**         ##@@@@@@--
		;;==@@@@@@@@@@##****..               **@@@@++

			**++++@@@@@@@@%%**    ....              --%%@@@@@@%%--
		==##@@@@@@@@@@@@@@@@@@;;  @@@@%%            **@@@@@@@@@@@@@@==  ==--
	**@@@@@@@@@@@@@@@@@@@@@@==  ++@@@@==        ..##@@@@@@@@++++@@@@@@@@@@##
	..##@@@@@@@@@@@@@@++%%@@@@@@..--@@@@@@      ##@@@@@@++;;    ++@@@@@@@@@@
	##@@@@@@@@++;;      ****==**--##@@@@@@  ..@@@@@@;;        ..==@@@@@@@@--
..@@@@@@##                  --@@@@@@@@@@    ==@@@@**      ..**%%@@@@@@@@##
;;@@@@==..                ==@@@@@@@@@@##    ==@@@@##====@@@@@@@@@@@@@@@@--
@@@@@@--          ..**##@@@@@@@@@@@@++      --##@@@@@@@@@@@@@@@@@@@@@@@@..
%%@@@@@@;;      ##@@@@@@@@@@@@@@@@--            ++@@@@@@@@@@@@@@@@@@@@%%
;;@@@@@@##==**==@@@@@@@@@@@@@@@@..                  ----------  %%@@@@@@;;
	--@@@@@@@@@@@@@@@@@@@@@@@@++..                          ;;@@@@@@%%
	##@@@@@@@@@@@@@@@@##++..                                --@@@@@@**
	##@@@@@@@@@@@@@@@@**                                    ..%%@@@@@@..
;;@@@@@@@@@@@@@@@@@@;;                                      ++@@@@@@**
@@@@@@@@##**%%@@@@@@--                                      ##@@@@@@..
@@@@@@##      @@@@@@==                                  ;;@@@@@@##..
%%@@@@@@@@++++@@@@@@@@--                                ;;@@@@@@@@;;
;;@@@@@@@@@@@@@@@@@@@@..                                ++@@@@@@++
	;;@@@@@@@@@@@@@@@@@@..                              --@@@@@@++
		--##@@@@@@@@@@++                                ++@@@@++
```
