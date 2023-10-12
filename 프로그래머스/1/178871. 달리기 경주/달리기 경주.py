def solution(players, callings):
    result = {player: i for i, player in enumerate(players)} # 선수: 등수
    for call_name in callings: 
        idx = result[call_name]
        result[call_name] -=1 # 등수 앞으로 진행 
        result[players[idx-1]] +=1
        players[idx-1], players[idx] = players[idx], players[idx-1]
    return players