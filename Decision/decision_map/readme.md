0416 버전

필요한 함수와 20초 데모로 이루어져 있고 매우 미완성인 버전입니다.


<value matrix>

각 위치 마다 가치(값)를 산정한 행렬입니다. 불연속적인 값을 가지며, 현재 행렬 크기는 (200,320)으로 경기장을 5cm 단위로 나눈 grid형태입니다. 크기 변경은 자유롭습니다. 처음 선언 시 행렬 크기를 자유롭게 변경 가능하나, 5:8 비율은 유지해줘야합니다.

시간/상황 마다 가치 행렬의 값은 변합니다.
아무것도 없는 공간의 기본 값은 50, 아예 갈수 없는 곳의 값은 0입니다.

<Behaviour>
0 (default) : go to starting point
1 : move to (x,y)
2 : patrol
3 : flee
4 : attack_1 : attack and move 
5 : attack_2 : attack and just rotate.
6 : occupy

사실 필수적인건 0,1,5,6이며 나머지는 부수적인 행동입니다.
2,3번의 경우 1번 이동 명령에서 최적 위치로 이동하는 명령으로 대체 가능하고,
4번은 가만히 chassis만 돌리면서 공격하는 모션,
5번은 좀 활발에게 이리저리 왔다갔다하며 공격하는 모션


<stance>

4가지 stance가 있고, 각 stance 마다 value_matrix의 산정방식이 달라집니다.
예를 들어 aggressive stance일 땐 적과 일정 거리 떨어진 곳이 가장 높은 점수가 되지만, passive stance일 땐 적에서 가장 먼쪽이 점수가 높아집니다.

4가지 aggressive, aggressive_low_ammo, aggressive_low_health, passive로 (bullets, health에 따른 구분)이 있습니다.


원래 cv2를 이용해 실시간 비디오 이미지를 쓰려 했으나 너무 이상하게 나와서 matplot을 씁니다.
