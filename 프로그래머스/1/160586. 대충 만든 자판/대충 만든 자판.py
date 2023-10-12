def solution(keymap, targets):
    # 딕션너리로 작성해놓고 최소값을 만드는 것 
    # target 에서 나올 때마다 딕션어리 값만 가져와서 더해준다.
    
    answer = []
    all = {}
    for str_i in keymap:
        for idx in range(len(str_i)):
            if str_i[idx] not in all:
                all[str_i[idx]] = idx+1
            else:
                if all[str_i[idx]] > idx+1:
                    all[str_i[idx]] = idx+1
    
    for str_i in targets:
        cnt = 0
        for idx in range(len(str_i)):
            if str_i[idx] in all:
                cnt += all[str_i[idx]]
            else: 
                cnt = -1
                break 
        answer.append(cnt)
        
    return answer