#include <Arduino.h>

#include <stdio.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#define TFT_CS        34 // GPIO34
#define TFT_RST       38 // GPIO38
#define TFT_DC        33 // GPIO33

#define BPOD_DISPLAY_BKLT 45

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const static char * Untitled_xpm[] PROGMEM = {
"128 160 71 1",
"   c #000000",
".  c #005D6B",
"+  c #006777",
"@  c #002D35",
"#  c #007485",
"$  c #008B9F",
"%  c #008093",
"&  c #003F4A",
"*  c #008295",
"=  c #008CA1",
"-  c #00869A",
";  c #006676",
">  c #00889C",
",  c #008DA2",
"'  c #007E91",
")  c #007081",
"!  c #004A55",
"~  c #008EA3",
"{  c #00899D",
"]  c #005361",
"^  c #008A9F",
"/  c #008498",
"(  c #008699",
"_  c #00879B",
":  c #005B69",
"<  c #007B8D",
"[  c #008A9E",
"}  c #007687",
"|  c #006E7F",
"1  c #007C8F",
"2  c #008194",
"3  c #008497",
"4  c #004C58",
"5  c #007F92",
"6  c #006B7C",
"7  c #00798B",
"8  c #008CA0",
"9  c #006271",
"0  c #006F80",
"a  c #00788A",
"b  c #007283",
"c  c #008599",
"d  c #007284",
"e  c #007587",
"f  c #008DA1",
"g  c #008EA2",
"h  c #008195",
"i  c #00616F",
"j  c #007A8C",
"k  c #006C7C",
"l  c #006B7B",
"m  c #006372",
"n  c #008397",
"o  c #008296",
"p  c #007C8E",
"q  c #00889D",
"r  c #008BA0",
"s  c #007384",
"t  c #007789",
"u  c #00899E",
"v  c #007D90",
"w  c #006878",
"x  c #008396",
"y  c #002A32",
"z  c #003038",
"A  c #008094",
"B  c #005360",
"C  c #000A0E",
"D  c #007688",
"E  c #004A56",
"F  c #006D7D",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                 .++@                                                                                                           ",
"                 #$%&                                                                                                           ",
"                @*=-&                                                                                                           ",
"                ;>,'@                                                                                                           ",
"                %,=)                                                                                                            ",
"               !-~{]                                                                                                            ",
"               !^$/@                                                                                                            ",
"               ](~'                                                                                                             ",
"               &_=*                                                                                                             ",
"               :_=<                                                                                                             ",
"               ;[[}                                                 !!!                                                         ",
"               |[[|                                                 +1+                                                         ",
"               |[[|                                                 1(1                                                         ",
"               |[[|                                                 2~2                                                         ",
"               |[[|                                                 (~(                                                         ",
"               ;[[}                                                 (~(      @@@                                                ",
"               :_=<                                                &-~3      +)+                                                ",
"               4_=5                                                6{=7      782]                                               ",
"               9{,5                                               !'=2.      5,=0                                               ",
"               a=,<                                               ]{{<       <,=a                                               ",
"               %,=)                                               b{,}       }$$b                                               ",
"              ]c,>:d'c'd!                                         %,=)       |[[|                                               ",
"              e=,-%[~,~^0@                                        -~$]       |[[|                                               ",
"              c~~$f~=8g,>6             @&444&@                   @-~-@       |[[|                                               ",
"             &$~~~('e)h,,<           !ij3____c-'k                )[,'        |[[|                                               ",
"             l,~~2+   m[,n         !do==,====~,~[2d@             %~=)        |[[|                                               ",
"             p~~q!    @3~3@        d[~,g_555*c$=~~[<!           @-,[]        |[[|                                               ",
"             *~~*      *,{:      @+2,r_jk    @]e-=~^d@          ]_f%@        |[[|                                               ",
"             *~~*      5,=s      @2=_#!         !jr,3@          1==}         t$$|                                               ",
"             *~~*      <,=a      ;u~[k.          @-~-@          o~=;         o,=;                                               ",
"             *~~*      )$$a      j,gf8d          +[~(           -,$]         c~$:                                               ",
"             *~~*      ]_='     !/,fr$>16       6-~,1          @3~3@         n,{4                                               ",
"             *~~*      @1~3+    )r=ce<,~[*'}||1o^~~3.          )[,'          *=_&                                               ",
"             *~~*       6(~7    %,,) .(~,~,$[[8~~,(+           %~=)          3~(@                                               ",
"             v,,v       @%=c6@  c,rw  +1{==$[[8=[<.           @-,[]         @(~3                                                ",
"             |[[|       @+3~_6  n~r0   @]0eb|||;]@            &_fn@         &_=*            @@@                                 ",
"             !++!         <g~{m 7,go]                         l{,<          s$,v        !d2(-{o)@                               ",
"                          mr~~0 ._g=0                         %,=)          v~=s      @6o=~~~,~[-'k                             ",
"                          @*,$0  #==-<m@                      c~$:          c,$:      +_~,=>c{8,,~^2d                           ",
"                           .66&  .do~,u<m@                   @c,>&          3~(@     k3g~>d! !k%[=~~$2d                         ",
"                                   6_,g,u<m@     @66m        &-=*@         @(~3      'g,%+     @]e>=~~^'i                       ",
"                                   @6v[,,,8cj]]b53[=7        a$,<         @6_=7      -,$]         !d>=~,/d@                     ",
"                                     @6<>,~~83-$,,,=7        %~=)         @5=3m     @c~c@           !j{,~_m                     ",
"                                        m<[8===$==>7.        c,$:         @3=-@     &_=*             @]x,,t                     ",
"                                          !ij*'}|;]@         *=_&         ]-~3@     4_=5               sr,2                     ",
"                                            @@@             @3~3@         e=,'      4_=5               ),,%                     ",
"                                                            &_=*          %,=)      4_=5              !o==e                     ",
"                                                            4_=5          %,^l      &_,c!           @do=,o]                     ",
"                                                            &%$#          5,=s      @3~86          ]v^~g[d                      ",
"                                                            @++.          t,=v       <,,n.       @+2=~=>d!                      ",
"                                                                          m38)       m-,,-'};:4l%_>,,{1]@                       ",
"                                                                          @++.       @d[=~,=[__{,~~3tm@                         ",
"                                                                                      !6'q~=[==,=$2+                            ",
"                                                                                         6e1}<5<)]@                             ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                @@@                                                                             ",
"               y&&z                            +2_1!                                                                            ",
"               .%A6                            +~~=e                                                                            ",
"               .^,cm                           +[~~e                                                                            ",
"               B2,,v@                          .3~-6                                                                            ",
"                m[~^6                         d',%6                                                                             ",
"                @%,,e         @]]!           d>~(+@                                          C@@y                               ",
"                 )88v       ij_q>+          .(~=1           @:m.y                            @w0.                               ",
"                 ]_='     @6o,~~=6        !d',8o!     !!k#5*38=_&                            &%>#                               ",
"                 @3~-]   @0>,,~~r:       ]'^~2d]   @mtn{(===~~~fD                            E-=v                               ",
"                  *,=0  @eu~,o>,^9     ]<_f,2+   @m%[,,$=-__3$~~_!                           4_=5                               ",
"                  <,=a @0{~,*.5,=s  !)%_=~,2i   .'[,~=_2ew4&@.>~=d              !i;]@        4_=5                               ",
"                  }$$b@0{~f*. <,=a k2=,g,['.   +3,~f_v:@      k{~2            d2>[[3d!       s[,<                               ",
"                  ;[[}6>~,'!  k$=>*>~,,[vm@   d(~~^v]          (~(  .++@    m'^~~[8,^0@      %~=)                               ",
"                  ]3=oq~~*.   !1~,=~$-sm@     2~,o6@          @(~3  #$%&  !d-,~=>j%,,>6      c,$:                               ",
"                  @28,,~-.     +1__2d!        >~[!            ]_='  5=_4 ko=,,>e! .q~~e      nf>&                               ",
"                   '~~~>d       @&&@          (~(             1==}  5=_4i-~~8'.    '~8)     @3~3@                               ",
"                   7,,^d                      (~-@           @/~8i  *=_:2,~^e!     d11!     ;{,'                   k77!         ",
"                   .dj;!                      3~r0@         !e^,3! @3~>%=,c;@               %,=)                   /~=i         ",
"                                              7,~>+        .'8,2.  )[,$,,oi                 -~$]                  ir~,|         ",
"                                              .3~,(2d!    mc,~^d   %~,,,{6                 ]q~-@                  '~~,|         ",
"                                               +73~~8o):Fv{~~ue!   -~~~8e@                 <=,<                  @-~~r|         ",
"                                                 +2=,,8_[,~,-0@   @_~~,1!                  c~$m                  er~,^|         ",
"                                                  !e{,8=,,[<.    @6=~~/i                  iq~/@                 !o~==[}         ",
"                                                   @6ev<5tm@     @c~~=i                   ',=e                  e=,r{=)         ",
"                                                                 :=~~/!                  ]q~[]                  %~,c=_w         ",
"                                                                 a~~,i                   ef,o@                 ]_,[>=_&         ",
"                                                                 3~~=!                   o,=k                  e=,'n~(&         ",
"                                                                 1~~'                   du~/!                  o,=)3=-@         ",
"                                                                 +11+                   '~=e         @m<3(3cc'5u~/;-='@         ",
"                                                                                       ]q,[]        .7[,~~~,~,,~~nD88v          ",
"                                                                                       e=,'@       .*,~~[(({$,~~~$r~,e          ",
"                                                                                       o,=k        7,~$v6 @&:>~~,,g~[6          ",
"                                                                                      kq~/!       @3,^0@    &-,r558,n@          ",
"                                                                                     @%~=e        ]_f%@     e$,'@0_=#           ",
"                                                                                    @er~{]        ;[[}     !o~$k!'~2.           ",
"                                                                                   !e^~8e@        |[[|     :$8c!1==1            ",
"                                                                                  +2=~,*!         |[[|     1r,}.q~f;            ",
"                                                                                  +~,8'.          i[$5!    %~=s7,,-]            ",
"                                                                                  +j2d!           !3~$6    c,r'>f']             ",
"                                                                                                   <,,n.  !3~$r,2.              ",
"                                                                                                   m-,,%m@j=g,g$d               ",
"                                                                                                   @d^,,[3=~~~8j!               ",
"                                                                                                    !0>,,~~~~$j!                ",
"                                                                                                     @6<n_,~80@                 ",
"                                                                                                         af,%                   ",
"                                                                                                         %,=)                   ",
"                                                                                                         o,{]                   ",
"                                                                                                        @3~3@                   ",
"                                                                                                        &_=*                    ",
"                                                                                                        4_=5                    ",
"                                                                                                        &_,>+                   ",
"                                                                                                        @2~~'.                  ",
"                                                                                                         d[=8+                  ",
"                                                                                                         !+1a+                  ",
"                                                                                                           @@@                  ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                ",
"                                                                                                                                "};

struct xpmHeader {
  int width;
  int height;
  int numColours;
  int charsPerPixel;
};

struct xpmHeader parseHeader(const char **xpm) {
  struct xpmHeader header;
  sscanf(xpm[0], "%d %d %d %d", &header.width, &header.height, &header.numColours, &header.charsPerPixel);
  return header;
}

struct colour {
  char character;
  uint16_t colour;
};

#define REDBITS 5
#define GREENBITS 6
#define BLUEBITS 5
#define REDSHIFT 11
#define GREENSHIFT 5
#define BLUESHIFT 0

struct colour * parseColours(const char **colourText, int numColours) {
  struct colour *colours = (struct colour *)malloc(sizeof(struct colour) * numColours);
  if (!colours)
    return NULL;
  for (int i = 0; i < numColours; i++) {
    const char *line = colourText[i];
    char character;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    sscanf(line, "%c  c #%2hhx%2hhx%2hhx", &character, &r, &g, &b);
    uint8_t r5 = r >> (8-REDBITS);
    uint8_t g6 = g >> (8-GREENBITS);
    uint8_t b5 = b >> (8-BLUEBITS);
    uint16_t colour16 = (r5 << REDSHIFT) | (g6 << GREENSHIFT) | (b5 << BLUESHIFT);

    colours[i] = { character, colour16 };
  }
  return colours;
}

uint16_t getColour(struct colour *colours, int numColours, char character) {
  for (int i = 0; i < numColours; i++) {
    if (colours[i].character == character)
      return colours[i].colour;
  }
  return 0;
}

void setup(void) {
  delay(500);

  Serial.begin(9600);
  Serial.print(F("HELLLLLLOOOOOOO BSIDES CANBERRAAAAAAAA"));
  Serial.print(F("@ajdlinux / @andrew.donnellan.id.au"));

  // Set backlight on full brightness
  pinMode(BPOD_DISPLAY_BKLT, OUTPUT);
  digitalWrite(BPOD_DISPLAY_BKLT, HIGH);

  // Initialise display
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.setRotation(2);

  Serial.println(F("=> Display initialised"));

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);

  struct xpmHeader header = parseHeader(Untitled_xpm);
  struct colour *colours = parseColours(Untitled_xpm + 1, header.numColours);

  for (int y = 0; y < header.height; y++) {
    for (int x = 0; x < header.width; x++) {
      char character = Untitled_xpm[y + 1 + header.numColours][x];
      uint16_t colour = getColour(colours, header.numColours, character);
      tft.drawPixel(x, y, colour);
    }
  }

  free(colours);
}

void loop() {
  //tft.invertDisplay(true);
  //delay(500);
  //tft.invertDisplay(false);
  //delay(500);
}
