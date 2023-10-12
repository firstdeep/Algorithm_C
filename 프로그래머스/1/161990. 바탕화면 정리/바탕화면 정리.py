def solution(wallpaper):
    
    min_x = 52
    min_y = 52
    max_x = 0
    max_y = 0
    
    for idx_y, y in enumerate(wallpaper):
        for idx_x, x in enumerate(y):
            if x=='#':
                if(min_x>idx_x): min_x = idx_x
                if(max_x<(idx_x+1)): max_x = (idx_x+1)
                if(min_y>idx_y): min_y = idx_y
                if(max_y<(idx_y+1)): max_y = (idx_y+1)
    
    answer = [min_y, min_x, max_y, max_x]
    return answer