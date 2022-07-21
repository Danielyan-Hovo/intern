with open("result.txt", 'w') as result:
    with open("exit.txt", "r") as exit:
        with open("golden.txt", "r") as golden:
            gold = golden.read().split('\n');
            ex = exit.read().split('\n')
            procent = 100
            l = len(gold)
            i = 1
            ex.pop(),gold.pop()
            for e,g in zip(ex,gold):
                if e == g:
                    result.write(f"Test {i} passed succesfully\n")
                    i += 1
                else:
                    result.write(f"Test {i} failed !!!")
                    i += 1
                    procent -= 100/l
            result.write(f"\n\n Tests results: {procent}%")
