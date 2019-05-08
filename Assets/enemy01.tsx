<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.2.3" name="enemy01" tilewidth="32" tileheight="36" tilecount="8" columns="0">
 <grid orientation="orthogonal" width="1" height="1"/>
 <tile id="0">
  <image width="32" height="36" source="Dungeon idle/big_demon_idle_anim_f0.png"/>
  <objectgroup draworder="index">
   <object id="1" x="5.75" y="8.75" width="19.5" height="27"/>
  </objectgroup>
 </tile>
 <tile id="1">
  <image width="32" height="36" source="Dungeon idle/big_demon_idle_anim_f1.png"/>
  <objectgroup draworder="index">
   <object id="1" x="5" y="8" width="20.5" height="28"/>
  </objectgroup>
 </tile>
 <tile id="2">
  <image width="32" height="36" source="Dungeon idle/big_demon_idle_anim_f2.png"/>
  <objectgroup draworder="index">
   <object id="1" x="5.75" y="7" width="20.5" height="28.75"/>
  </objectgroup>
 </tile>
 <tile id="3">
  <image width="32" height="36" source="Dungeon idle/big_demon_idle_anim_f3.png"/>
  <objectgroup draworder="index">
   <object id="1" x="6" y="10" width="21.25" height="26.5"/>
  </objectgroup>
 </tile>
 <tile id="4">
  <image width="32" height="36" source="Dungeon idle/big_demon_run_anim_f0.png"/>
  <objectgroup draworder="index">
   <object id="2" x="4.75" y="6.25" width="21.25" height="29.5"/>
  </objectgroup>
 </tile>
 <tile id="5">
  <image width="32" height="36" source="Dungeon idle/big_demon_run_anim_f1.png"/>
  <objectgroup draworder="index">
   <object id="1" x="4.5" y="4.5" width="21.75" height="30.25"/>
  </objectgroup>
 </tile>
 <tile id="6">
  <image width="32" height="36" source="Dungeon idle/big_demon_run_anim_f2.png"/>
  <objectgroup draworder="index">
   <object id="1" x="5.25" y="3" width="20.25" height="32.75"/>
  </objectgroup>
 </tile>
 <tile id="7">
  <image width="32" height="36" source="Dungeon idle/big_demon_run_anim_f3.png"/>
  <objectgroup draworder="index">
   <object id="1" x="4.75" y="9.5" width="21.75" height="26.25"/>
  </objectgroup>
  <animation>
   <frame tileid="0" duration="100"/>
   <frame tileid="1" duration="100"/>
   <frame tileid="2" duration="100"/>
   <frame tileid="3" duration="100"/>
   <frame tileid="4" duration="100"/>
   <frame tileid="5" duration="100"/>
   <frame tileid="6" duration="100"/>
   <frame tileid="7" duration="100"/>
  </animation>
 </tile>
</tileset>
