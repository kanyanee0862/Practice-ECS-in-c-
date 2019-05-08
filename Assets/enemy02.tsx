<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.2.3" name="enemy02" tilewidth="8" tileheight="8" tilecount="4" columns="0">
 <grid orientation="orthogonal" width="1" height="1"/>
 <tile id="0">
  <image width="8" height="8" source="Dungeon idle/coin_anim_f0.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0.5" y="0.5" width="6.75" height="7.75">
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="1">
  <image width="8" height="8" source="Dungeon idle/coin_anim_f1.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0.5" y="1.25" width="6.5" height="6.25">
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="2">
  <image width="8" height="8" source="Dungeon idle/coin_anim_f2.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0.75" y="0.5" width="6" height="7">
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="3">
  <image width="8" height="8" source="Dungeon idle/coin_anim_f3.png"/>
  <objectgroup draworder="index">
   <object id="1" x="0.5" y="0" width="6.75" height="8.25">
    <ellipse/>
   </object>
  </objectgroup>
  <animation>
   <frame tileid="0" duration="100"/>
   <frame tileid="1" duration="100"/>
   <frame tileid="2" duration="100"/>
   <frame tileid="3" duration="100"/>
  </animation>
 </tile>
</tileset>
