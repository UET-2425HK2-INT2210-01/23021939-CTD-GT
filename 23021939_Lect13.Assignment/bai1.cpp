
I. /<[^>]+>/
  1) <an xml tag>
  2) <opentag> <closetag>
  3) </closetag>
  5) <with attribute=”77”>

II. /a.[bc]+/
  1) abc
  2) abbbbbbbb
  3) azc
  4) abcbcbcbc
  6) azccbbbbcbccc

III. /(very )+(fat)?(tall|ugly) man/
  1) very fat man
  3) very very fat ugly man
  4) very very very tall man

IV. Chuỗi dạng "abc.def.ghi.jkx"
  ^.{3}\..{3}\..{3}\..{3}$

V. Số điện thoại
  ^(\(\d{3}\)|^\d{3})[-. ]?\d{3}[-. ]?\d{4}$

VI. Chuỗi validate
  ^(?!.*[-_ ]{2})[a-zA-Z0-9]+(?:[-_ ][a-zA-Z0-9]+)*$
