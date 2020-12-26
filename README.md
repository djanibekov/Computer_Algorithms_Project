# Computer_Algorithms_Project

## Map - Graph
|City|A|B|C|D|E|F|G|H|I|J|
|A|0| 150| 300| 200| inf| inf| inf| inf| inf| inf|
|B|140| 0| 100| inf| 200| inf| inf| inf| inf| inf|
|C|290| 90| 0| 100| inf| 400| inf| inf| inf| inf|
|D|190| inf| 90| 0| inf| inf| 300| inf| inf| inf|
|E|inf| 190| inf| inf| 0| inf| inf| 200| inf| inf|
|F|inf| inf| 390| inf| inf| 0| inf| 250| 300| 100|
|G|inf| inf| inf| 290| inf| inf| 0| inf| inf| 200|
|H|inf| inf| inf| inf| 190| 240| inf| 0| 100| inf|
|I|inf| inf| inf| inf| inf| 290| inf| 90| 0| inf|
|J|inf| inf| inf| inf| inf| 90| 190| inf| inf| 0|

## Short Ways Value
|City|A|B|C|D|E|F|G|H|I|J|
|A|0| 150| 250| 200| 350| 650| 500| 550| 650| 700|
|B|140| 0| 100| 200| 200| 500| 500| 400| 500| 600|
|C|230| 90| 0| 100| 290| 400| 400| 490| 590| 500|
|D|190| 180| 90| 0| 380| 490| 300| 580| 680| 500|
|E|330| 190| 290| 390| 0| 440| 690| 200| 300| 540|
|F|620| 480| 390| 490| 440| 0| 290| 250| 300| 100|
|G|480| 470| 380| 290| 670| 290| 0| 540| 590| 200|
|H|520| 380| 480| 580| 190| 240| 530| 0| 100| 340|
|I|610| 470| 570| 670| 280| 290| 580| 90| 0| 390|
|J|670| 570| 480| 480| 530| 90| 190| 340| 390| 0|

## Connected cities
|City|A|B|C|D|E|F|G|H|I|J|
|A|0| 0| 1| 0| 1| 2| 3| 4| 7| 6|
|B|0| 0| 0| 2| 0| 2| 3| 4| 7| 5|
|C|1| 0| 0| 0| 1| 0| 3| 4| 7| 5|
|D|0| 2| 0| 0| 2| 2| 0| 4| 7| 6|
|E|1| 0| 1| 2| 0| 7| 3| 0| 7| 7|
|F|2| 2| 0| 2| 7| 0| 9| 0| 0| 0|
|G|3| 3| 3| 0| 3| 9| 0| 9| 9| 0|
|H|4| 4| 4| 4| 0| 0| 9| 0| 0| 5|
|I|7| 7| 7| 7| 7| 0| 9| 0| 0| 5|
|J|6| 5| 5| 6| 7| 0| 0| 5| 5| 0|


```bash
number of element: 5
knapsack size: 12

weight: 5
value: 15000
destination: 8

weight: 3
value: 1
destination: 4

weight: 3
value: inf
destination: 2

weight: 3
value: 900
destination: 1

weight: 3
value: 600
destination: 5
```