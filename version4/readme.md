그냐 아무대나 넣고 돌리면 됨. 자체 가지고 다니고 있음

main.py가 진짜 파일
test.py는 그냥 위치만 뽑아서 확인해보려고 만든 코드

test.py는 4개의 위치를 한줄에 하나씩 뽑는 코드


주의사항!!!!!!!

로봇 이름을 r1, r2, r3, r4로 지음. 근데 로스 상에서는 robot_0, robot_1, robot_2, robot_3로 되어 있음. 그냥 
robot_0 = r1
robot_1 = r2
robot_2 = r3
robot_3 = r4

로 정의했음. 아무 문제 아니나 헷갈리지 마시길


그리고 지금 위치가 다 똑같은 곳으로 보여서 계산 코드 상 현재 위치에 가치가 0이 되어 정상적인 움직임이 아님.