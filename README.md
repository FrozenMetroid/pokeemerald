# Pokémon Emerald

This is a decompilation of Pokémon Emerald that has been modified to be the ideal version of Emerald for Senate/Frozen_Metroid.

All credits for the decompilation efforts lie with the contributors of pokeemerald!

# Senate/Frozen_Metroid Changes:

## Bug/Issue Fixes

- All bugs identified by the pokeemerald contributors have been fixed
- Omanyte's missing pixel has been filled in

## Battle

### Abilities
- New to Generation 3
  - Filter
    - Aggron
  - Harvest
   - Exeggutor and Tropius
  - Heatproof
    - Glalie and Regice
  - Rivalry
    - Seviper and Zangoose
  - Technician
    - Persian, Scyther, Aipom, Scizor, Smeargle, and Hitmontop
  - Scrappy
    - Kangaskhan, Miltank, Swellow, and Exploud
  - Skill Link
    - Cloyster
  - Solid Rock
    - Rhydon, Camerupt, and Regirock
- Changes to Abilities
  - Sturdy prevents OHKOs at full health, like generation 5 and onward
  - Overgrow, Torrent, Blaze, and Swarm always give a 20% boost to their respective types

### General Mechanics
- Trainer Data overhaul: can now specify nature, ability, IVs/EVs, etc.
- Updated spread moves (Earthquake, Surf, etc.) to deal 75% damage in double battles rather than 50%
- Added Physical/Special split (note: not reflected visually in-game)
- Hail
  - Makes Blizzard perfectly accurate
  - Gives Ice-types a 50% defense boost
- Sandstorm
  - Gives Rock-types a 50% special defense boost
- Items are restored at the end of battle, except for Berries and Mail (if the latter can even be removed in the first place)

### Moves
- Air Cutter: BP increased from 55 to 65
- Ancient Power: BP increased from 60 to 65, PP increased from 5 to 15
- Blizzard: Perfectly accurate in Hail
- Cut: Type changed from Normal to Steel, accuracy increased from 95 to 100
- Fly: BP increased from 70 to 90, accuracy increased from 95 to 100
- Fury Cutter: BP increased from 10 to 30, maximum damage set to 160
- Hidden Power: BP standardized to 60BP
- Knock Off: BP increased from 20 to 40, now deals 1.5x damage if the target has an item
- Leech Life: Modernized to 80BP
- Meteor Mash: Modernized to 90BP and 90 accuracy
- Rock Smash: BP increased from 20 to 50
- Silver Wind: BP increased from 60 to 65, PP increased from 5 to 15
- Shadow Punch: BP increased from 60 to 80
- Triple Kick: BP increased from 10 to 15 (60BP to 75BP)

### Pokémon
- Stats for almost every Pokémon have been changed to buff weaker choices
- Learnsets for almost every Pokémon have also been changed to make every choice viable and to give easier access to STAB attacks (looking at you Lombre and Nuzleaf)

## Field

### Encounters
- New Species Added To Hoenn Pokédex
  - Fiery Path
    - Magby
  - Magma Hideout
    - Magmar
  - Mt. Pyre
    - Misdreavus
  - New Mauville
    - Elekid
  - Rusturf Tunnel, Granite Cave, Magma Hideout
    - Onix
  - Shoal Cave
    - Smoochum
    - Jynx
    - Sneasel
  - Underwater (124 & 126)
    - Shellder
  - Victory Road
    - Steelix
  - Water Routes (Surf)
    - Mantine
- Swarms/Outbreaks
  - Treecko
    - Route 119
  - Torchic
    - Route 121
  - Mudkip
    - Route 120
  - Bagon
    - Meteor Falls
  - Surskit
    - Route 114

### QoL
- TMs are infinite
- Pokémon can relearn moves from the party menu without a Heart Scale.
- Overworld poison has been removed
- Pokémon with the Ability Harvest will grant one additional Berry when they are the first Pokémon in the party when collecting Berries (CalcBerryYieldInternal)
- Decreased the cost of coins from the Game Corner to reduce the grinding

### Items
- A clerk on the second floor of the department store now sells evolution stones and the Linking Cord (used to evolve Haunter, Kadabra, Machoke, and Graveler)
- A new Water Stone has been added to Route 114 near the Persim Berries (requires Surf)