# Changelog

## [0.6.0] - 2025-01-25

### Added
- Introduce the `ListInterface`, which defines the unified API for all
`AbstractList` implementations. It includes common methods `insert`, `remove`, 
`find`, `getSize`, `isEmpty`, and`clear`. This interface also supports element
access and modification using the `[]` operator.

### Changed
- Combine the `Array` and `List` functionalities to `ArrayList`, 
which now serves as the replacement for the previous `List` class.
- Reimplement `LinkedList`. Some previously supported methods
are no longer available.

### Removed
- Removed the standalone `array` class.

## [0.5.0] - 2025-01-19

### Added
- Introduce class `list` and methods `set`, `get`, `getCapacity`, `extend`,
and default ADS methods.

## [0.4.0] - 2025-01-19

### Added
- Introduce new methods for linked list, including `set`, `get`, `getSize`,
`isEmpty`, `pop_back`, `insert`, `remove`, `find`, `clear`, `traverse`. Basic
methods for linked lists are complete.

### Changed
- Refactor and rename methods for linked list, including `pop_front`, 
`push_front`, `push_back`.

## [0.3.0] - 2025-01-16
### Added
- Class `AbstractDataStructure`.
  - Virtual methods `insert`, `remove`, `find`, `getSize`, `isEmpty`,
  `clear`, `traverse`.
- Introduces new methods of array, including all methods above.

### Changed
- The implement of class `Array` is now derived from `AbstractDataStructure`.
- Refactors Array methods `set`, `get`, `getSize`.


## [0.2.0] - 2025-01-15
### Added
- Class `LinkedList`.
  - Methods `insertHead`, `insertTail`, `deleteHead`, `traverse`.


## [0.1.0] - 2025-01-15
### Added
- Class `Array`.
  - Methods `set`, `get`, `getSize`.
