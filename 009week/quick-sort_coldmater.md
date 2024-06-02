# 퀵정렬

#재귀적 #분할정복 #피벗

- 평균 $O(N\log{N})$
- 최악 $O(N^2)$
- 메모리 $O(\log{N})$
- 안정성 유지되지 않음

질문: divide and conquer VS decrease and conquer(?) -> decrease and conquer 가 뭐지? 🤔

## 메인 컨셉

### 피벗

배열 요소 중 하나를 선택

- 피벗 선택 방법에 따라 이름도 있을 정도 (로무토 분할법, 호어 분할법 등 - 나름 최악 시간복잡도 나오는 것을 줄이기 위해 임의성을 추가하는 일련의 방법이라고 생각됨)

### 분할정복

배열을 순회하며 피벗을 기준으로 두 부분으로 나눔, 더 이상 나누지 못할 때까지 반복

### 파티셔닝: swapping & 투포인터 & sweeping

배열을 두 부분으로 나누기 위해 원본 배열만을 사용함 (스위핑)

- 호출 깊이에만 영향을 받아 `공간복잡도`는 $O(\log{N})$ 임

## 분할정복

배열을 피벗값을 기준으로 좌측, 우측으로 나눈다. (오름차순 기준으로는 좌측은 피벗보다 작은 값들)

나뉘어진 각 부분에 대해서 동일하게 피벗을 선택, 피벗값을 기준으로 좌측, 우측을 나눈다. 다시 각 부분에 대해 동일한 로직을 적용한다.

요소가 1개만이 남았을 때 함수를 종료한다.

## 함수가 한 번 호출될 때

세 가지 포인터를 활용하여 (`R`(=Pivot), `L`(=Left), `i`(=index)) 다음의 과정을 거치면 과정 하나(함수 호출 1회)에 대하여 정렬을 수행한다.

원본 메모리 공간을 사용하여, 추가 메모리 공간을 사용하지 않도록 하기 위한 방법이다.

배열(arr)이 주어지고, 특정 값(v)이 주어졌을 때 특정 값을 기준으로 원본 배열을 두 부분으로 나누는 방법

[3,7,2,6,9,3,2] 와 5 가 주어졌다고 하면 [3,2,3,2, 6,9,7] 과 같이 5를 기준으로 두 부분으로 나뉘게 하는 방법이다.

1. 맨 오른쪽 요소(n-1)를 피벗으로 선택한다. (R)
   - 하지만, 요소가 꼭 맨 오른쪽 요소일 필요는 없다.
2. 맨 왼쪽 요소를 Left 라고 지정한다.
3. idx 0 ~ n-2 까지 순회하면서 각 단계에서 다음의 과정을 반복한다.

   1. `i` 의 값이 `R` 보다 **작으면**
      1. L 위치의 요소와 i 위치의 요소를 교환(swap)한다.
      2. L 을 +1 해준다. (오른쪽으로 한 칸 민다.)
   2. `i` 의 값이 `R` 보다 **크면** 아무것도 하지 않는다.

4. (3. 의 순회를 마치면) Pivot 과 L 의 요소를 교환한다.

> [!NOTE]
> 이 부분은 알고리즘으로는 와닿지 않지만, 실제로 해보면 그렇게 된다는 사실을 쉽게 받아들일 수 있다.
>
> 1. 모든 배열이 피벗값보다 작다고 가정하고 진행해보기
> 2. 모든 배열이 피벗값보다 크다고 가정하고 진행해보기
> 3. 배열 요소에 피벗보다 큰 값, 작은 값을 한 개씩 넣어 진행해보기
> 4. 배열 요소에 피벗보다 큰 값, 작은 값을 각각 2개씩 넣어 진행해보기
>
> 추가로 본 과정의 의의는 다음과 같다.
>
> - pivot 에 해당하는 값의 위치를 찾기
> - pivot 을 기준으로 작은값은 왼쪽에 위치시키고 큰 값은 pivot 의 오른쪽에 위치시킴

이 과정을 거치고 나면 pivot 의 위치는 확정이다! pivot 의 왼쪽은 무조건 pivot 보다 작은 값, 오른쪽은 pivot 보다 큰 값이 된다.

위 과정을 거친 뒤, 분할된 각 영역에 대해 동일한 적용을 반복해준다. (재귀)

### L 의 의미 (스토리텔링 방식으로 기억하기)

: L 은 pivot 의 최종 위치(반복문 내에서는 이 위치를 찾아가는 도중의 임시 위치)이고, 각 요소와 비교하며 pivot 보다 왼쪽에 있을지, 오른쪽에 있을지를 결정하게 된다.

사실상 L 은 위 로직이 끝난 뒤 Pivot 의 위치를 의미한다.

i 위치의 값이 pivot 보다 큰 값이면 그대로 둔다. 최종로직(pivot 과 L 의 위치를 변경) 이 수행되면 L 에 pivot 값이 와야 pivot 이 작은 값으로써 왼쪽에 있을 수 있게 된다.

i 위치의 값이 pivot 보다 작은 값이면 L 과 i 의 위치를 바꾼다. L 은 최종적으로는 pivot 의 위치이기 때문에, i 의 값이 pivot 보다 작다면, pivot 보다 왼쪽에 있어야 하기 때문이다. L 의 위치는 항상 i 보다 작거나 같을 것이므로, 두 위치를 바꿔준다는 것의 의미는 L이 i 보다 오른쪽에 있게 하기 위해서이다.

L 을 한 번 오른쪽으로 밀어준다는 것의 의미: 스왑 뒤 L 의 위치에는 pivot 보다 작은 값이 위치해 있을 것이다. 해당 위치는 최종적으로 pivot 과 스왑되게 될텐데, pivot 보다 작은 값인게 그대로 L 로 있게 되면 스왑 후 pivot 이 작은값보다 왼쪽에 있게 되기 때문에 L 은 오른쪽으로 한 칸 민다.

# quicksort visualization

https://opendsa-server.cs.vt.edu/embed/quicksortAV
서브어레이를 파티셔닝하는 과정이 위에서 설명한 방식과는 조금 다르지만 (서브어레이의 투포인터를 양 끝 지점으로 설정한 점 - 위 설명에서는 투포인터(`L`과 `i` 가 같은 위치에서 시작함)) O(N) 시간복잡도 내에 파티셔닝 한다는 점에서는 동일하다.

# 더 알아보기

## 더블 피벗 퀵소트

기존 one-pivot 방식의 특정 데이터셋이 O(n^2)으로 처리되는 많은 경우를 커버. 여전히 최악의 시간복잡도는 O(n^2)이지만, 피벗을 2개로 운영하는 것으로 재귀 깊이를 줄이고 대체적인 성능 개선을 이룸