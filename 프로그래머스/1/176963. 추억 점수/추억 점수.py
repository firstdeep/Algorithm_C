def solution(name, yearning, photo):
    name_db = {y:x for y, x in zip(name, yearning)}
    answer = []
    for idx in photo:
        count = 0 
        for who in idx: 
            #print(who)
            if who in name_db:
                count += name_db[who]
        answer.append(count)
    
    return answer