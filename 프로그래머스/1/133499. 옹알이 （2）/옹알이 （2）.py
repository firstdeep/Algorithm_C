def solution(babbling):
    answer = 0
    check = ["aya", "ye", "woo", "ma"]
    for word in babbling:
        for check_word in check:
            if check_word*2 not in word:
                word=word.replace(check_word,' ')
                # print("i =", word)
        if len(word.strip())==0:
            answer +=1
   
    return answer