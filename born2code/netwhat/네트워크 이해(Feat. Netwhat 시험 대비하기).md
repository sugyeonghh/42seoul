

# 네트워크 이해(Feat. Netwhat 시험 대비하기)

-   목차 :
    -   IP address가 무엇인지. (1)
        
    -   Netmask (2)
        
    -   IP with Netmask의 subnet (3)
        
    -   subnet의 Broadcast 주소 (4)
        
    -   ip 주소 with Netmask를 나타내는 여러 가지 방법 (5)
        
    -   public && private IP의 차이점 (6)
        
    -   IP 주소의 class (7)
        
    -   TCP (8)
        
    -   UDP (9)
        
    -   network 레이어가 무엇인지 (10)
        
    -   OSI model (11)
        
    -   DHCP 서버 그리고 DHCP 프로토콜 (12)
        
    -   DNS 서버 그리고 DNS 프로토콜 (13)
        
    -   IP 주소를 가지고 두 개의 디바이스가 통신하도록 만들 때의 규칙 (14)
        
    -   IP를 가지고 라우팅(routing) 하는 것이 어떻게 돌아가는지 (15)
        
    -   라우팅을 위한 기본(default) Gateway (16)
        
    -   IP 관점에서의 포트(port)는 무엇인지, (17)
        
    -   그리고 다른 기기와 연결할 때 그 사용용도는 무엇인지 (18)
        

IP address가 무엇인지. (1)

+ Netmask (2)  
+ IP with Netmask의 subnet (3)  
+ subnet의 Broadcast 주소 (4)  
+ public && private IP의 차이점 (6)  
+ IP 주소의 class (7)

[https://m.blog.naver.com/PostView.nhn?blogId=hatesunny&logNo=220790654612&proxyReferer=https%3A%2F%2Fwww.google.com%2F](https://m.blog.naver.com/PostView.nhn?blogId=hatesunny&logNo=220790654612&proxyReferer=https%3A%2F%2Fwww.google.com%2F)

(1) (2) (3) (4) (5) (6) (7) 에 대한 추가 자료가 필요하다면 :

[https://42kchoi.tistory.com/22?category=887188](https://42kchoi.tistory.com/22?category=887188)

network 레이어가 무엇인지 (10)

+ OSI model (11)

[https://m.blog.naver.com/hatesunny/220789832663](https://m.blog.naver.com/hatesunny/220789832663)

+) 프로토콜이란?  
[https://m.blog.naver.com/hatesunny/220788662088](https://m.blog.naver.com/hatesunny/220788662088)

+) 포트번호 간략히  
[https://m.blog.naver.com/hatesunny/220788811541](https://m.blog.naver.com/hatesunny/220788811541)

+) tcp 헤더  
[https://m.blog.naver.com/hatesunny/220790300052](https://m.blog.naver.com/hatesunny/220790300052)

* TCP (8)

[https://m.blog.naver.com/hatesunny/220790242308](https://m.blog.naver.com/hatesunny/220790242308)  

* UDP (9)

[https://m.blog.naver.com/hatesunny/220790304526](https://m.blog.naver.com/hatesunny/220790304526)  

* TCP (8) + UDP (9)

[https://run-it.tistory.com/20?category=668092](https://run-it.tistory.com/20?category=668092)

* DHCP 서버 그리고 DHCP 프로토콜 (12)

[https://terms.naver.com/entry.nhn?docId=2835899&cid=40942&categoryId=32851](https://terms.naver.com/entry.nhn?docId=2835899&cid=40942&categoryId=32851)  
[https://lhh3520.tistory.com/285](https://lhh3520.tistory.com/285)  

* DNS 서버 그리고 DNS 프로토콜 (13)

[https://youtu.be/2ZUxoi7YNgs](https://youtu.be/2ZUxoi7YNgs)  
[https://run-it.tistory.com/32?category=668092](https://run-it.tistory.com/32?category=668092)  
[https://webdir.tistory.com/161](https://webdir.tistory.com/161)  
[https://galid1.tistory.com/53](https://galid1.tistory.com/53)  

* IP를 가지고 라우팅(routing) 하는 것이 어떻게 돌아가는지 (15)

[https://bignet.tistory.com/26](https://bignet.tistory.com/26)

-   요약 : 라우팅(Routing)
    -   1.  ip주소확인 (스시 맛집(개포동 연스시임을 확인))
    -   2.  경로를 확인하고 (선릉역에서 개포동역으로 가야함을 확인.)
    -   3.  어느 인터페이스로 내보내야하는지 결정. (여러 지하철 호선 중 분당선을 타야함을 확인.)
    -   4.  결정한 인터페이스로 패킷 전달->다른 라우터에 도달 (분당선 타고 개포동으로 감.)
    -   5.  1~4 반복. 목적지 네트워크에 도착할 때까지.
-   동적, 정적 라우팅 :  
    [http://blog.naver.com/PostView.nhn?blogId=ssdyka&logNo=221068508093&parentCategoryNo=&categoryNo=11&viewDate=&isShowPopularPosts=true&from=search](http://blog.naver.com/PostView.nhn?blogId=ssdyka&logNo=221068508093&parentCategoryNo=&categoryNo=11&viewDate=&isShowPopularPosts=true&from=search)

* 일반 게이트웨이 :  
  [https://brownbears.tistory.com/195](https://brownbears.tistory.com/195)  

* 기본 게이트웨이(16)

+) IP 주소를 가지고 두 개의 디바이스가 통신하도록 만들 때의 규칙 (14)

+) ip 주소 with Netmask를 나타내는 여러 가지 방법 (5) 개념 살짝  
: [https://yang1650.tistory.com/25](https://yang1650.tistory.com/25)  

+ 기본 게이트웨이++  
: [https://eunguru.tistory.com/171](https://eunguru.tistory.com/171)

IP 관점에서의 포트(port)는 무엇인지, (17)  
+ 그리고 다른 기기와 연결할 때 그 사용용도는 무엇인지 (18)

[https://run-it.tistory.com/19](https://run-it.tistory.com/19)  
+ 포트 ++ :  
[https://m.blog.naver.com/wind1237/140190026607](https://m.blog.naver.com/wind1237/140190026607)  
"어떤 응용 프로그램, 또는 사용자가 보낸 데이터인지를 구분하기 위해

송신측 포트 번호(Source Port Number)가 사용되고,  
어느 응용 프로그램이 수신해야 하는지를 구분하기 위해  
수신측 포트 번호(Destination Port Number)가 사용된다."



https://42kchoi.tistory.com/23?category=887188

<- md 파일을 열기 힘든 분들은 여기서도 확인 가능