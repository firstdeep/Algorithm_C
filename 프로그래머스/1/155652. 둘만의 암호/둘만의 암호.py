def solution(s, skip, index):
    # 아스키코드값으로 넘어갔다가 다시 넘어오는 코드 필요 
    # 아스키코드값이 필요가 없구나...
    
    answer = ''
    alpha = "abcdefghijklmnopqrstuvwxyz"
    
    for ch in skip:
        if ch in alpha:
            alpha = alpha.replace(ch,"")
    
    for i in s:
        # 다시 돌아가는 것 까지 생각해줘야 한다. 모듈러 사용 
        change = alpha[(alpha.index(i)+index)%len(alpha)]
        answer += change
    
    return answer