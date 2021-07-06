
# 소개
증강현실 공간을 구축하기 위해서는 점군, 오브젝트, 평면 등 실제 공간의 유의미한 인식 과정이 필요합니다.
기존의 실내 공간 인식 방법은 철저하게 관측 가능한 공간에 대해서만 평면 검출이 가능하며, 밀도와 노이즈의 변화에 민감합니다.
이는 증강현실이 활용되는 실내 공간의 특성을 이해하여 극복할 수 있습니다.
증강현실이 활용되는 대부분 실내 공간은 방이며, 대부분의 방은 직육면체 모양입니다.

<div align="center">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124558748-e6398000-de75-11eb-8d7d-8484a81dd381.png" height="200">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124558742-e46fbc80-de75-11eb-9ac0-1367a96f47d5.png" height="200">
</div>

본 연구 프로그램은 직육면체 방 형태의 실내 공간에서 점군 데이터 기반 직육면체 볼륨 검출을 통해 빠르고 정확하게 AR 게임 공간을 구성하는 방법을 제안합니다.
제안 방법은 기존의 평면 검출 알고리즘에서 벗어나 Oriented Bounding Box (OBB) 검출 방법을 기반으로 한 Top-Down 방식을 활용합니다.
또한, 공간 인식의 효율을 극대화하고 표현의 자유도를 높이기 위해 구면 파노라마 비디오를 기반으로 합니다.

# 상세 설명
<div align="center">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124558909-0ff2a700-de76-11eb-8b98-08fce231608d.png" height="200">
  <img class="scalezoom_small" src="https://user-images.githubusercontent.com/32832618/124558917-1123d400-de76-11eb-8b91-d120b923d287.png" height="200">
</div>
 
볼륨 검출 과정은 3개의 주요 과정으로 구성됩니다.
먼저, 구면 파노라마 기반의 Vision SLAM을 통해 실시간으로 점군 데이터를 획득하고, KDTree를 구성해 이웃점과 거리가 먼 이상점을 제거합니다.
다음으로, 점군 데이터를 감싸는 최적의 OBB를 검출합니다.
마지막으로, 생성된 OBB 볼륨의 품질을 정량적으로 평가하고, 실시간으로 좋은 품질의 OBB로 생산합니다.

볼륨 검출 과정 이후에는, 먼저 구면 파노라마의 왜곡을 제거하기 위해 3차원 큐브맵 이미지로 변환합니다.
큐브맵 이미지는 거대한 스카이박스처럼 가상 세계 안에 매우 큰 정육면체 형태로 배치합니다.
다음으로, 가상 세계 안에서의 카메라의 위치 및 자세를 플레이어와 큐브맵 정육면체에 반영합니다.
마지막으로, 볼륨 검출 과정을 통해 획득한 OBB의 6개의 평면을 가상 세계에 배치합니다.
더욱 자세한 내용은 하단의 버튼을 통해 확인하실 수 있습니다.

# cuboid-volume-ar-space
This is AR workspace generation method using volume detection based on point clouds of spherical panorama


# If you want to compile this project
- It is developed using UE 4.19.2 Environment

- Compile with visual studio 2017 in "Development Editor" + "Win64" mode.
- Change Pathes String in mainST.cpp(this is main singletone) in C++ script then build.
- Before c++ build, delete solution file(LetsGo.sln), then execute "Generate Visual Studio Project File" in .uproject.

- Before testing program, you need to store your data in LetsGo/inputs/...
- We commite without input videos because of size. so add videos of spherical panorama
