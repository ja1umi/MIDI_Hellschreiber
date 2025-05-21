//
// Stroke-like font data for Hellschreiber (including Chirp Hell)
//

const uint8_t Letter_J2[] = {
  SET_DIV, 1, BGN_COL,   1,                END_COL,
  SET_DIV, 1, BGN_COL, 0,
  SET_DIV, 2, BGN_COL, 0,               6, END_COL,
  SET_DIV, 6, BGN_COL,   1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 1, BGN_COL,                  6, END_COL,
  EOD
};

const uint8_t Letter_A2[] = {
  SET_DIV, 5, BGN_COL, 0, 1, 2, 3, 4,       END_COL,
  SET_DIV, 5, BGN_COL,       2,       5,    END_COL,
  SET_DIV, 5, BGN_COL,       2,          6, END_COL,
  SET_DIV, 5, BGN_COL,       2,       5,    END_COL,
  SET_DIV, 5, BGN_COL, 4, 3, 2, 1, 0,       END_COL,
  EOD
};

const uint8_t Letter_12[] = {
  SKIP_COL,
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 1, BGN_COL,                   6, END_COL,
  SKIP_COL,
  EOD
};

const uint8_t Letter_U2[] = {
  SET_DIV, 6, BGN_COL,  1, 2, 3, 4, 5, 6,   END_COL,
  SET_DIV, 1, BGN_COL, 0,                   END_COL,
              BGN_COL, 0,                   END_COL,
  SET_DIV, 1, BGN_COL, 0,                   END_COL,
  SET_DIV, 6, BGN_COL,  1, 2, 3, 4, 5, 6,   END_COL,
  SKIP_COL,
  EOD
};

const uint8_t Letter_M2[] = {
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 1, BGN_COL,                5,    END_COL,
  SET_DIV, 2, BGN_COL,          3, 4,       END_COL,
  SET_DIV, 1, BGN_COL,                5,    END_COL,
  SET_DIV, 7, BGN_COL, 6, 5, 4, 3, 2, 1, 0, END_COL,
  SKIP_COL,
  EOD
};

const uint8_t Letter_I2[] = {
  SKIP_COL,
  SET_DIV, 1, BGN_COL, 0,                   END_COL,
  SET_DIV, 5, BGN_COL, 0, 1, 2, 3,       6, END_COL,
  SKIP_COL,
  EOD
};

const uint8_t Letter_slash2[] = {
//  SET_DIV, 1, BGN_COL,  0,              END_COL,
  SET_DIV, 1, BGN_COL,    1,            END_COL,
  SET_DIV, 1, BGN_COL,      2,          END_COL,
  SET_DIV, 1, BGN_COL,        3,        END_COL,
  SET_DIV, 1, BGN_COL,          4,      END_COL,
  SET_DIV, 1, BGN_COL,            5,    END_COL,
//  SET_DIV, 1, BGN_COL,              6,  END_COL,
  EOD
};

const uint8_t Letter_V2[] = {
  SET_DIV, 5, BGN_COL,      6, 5, 4, 3, 2,  END_COL,
  SET_DIV, 1, BGN_COL,    1,                END_COL,
              BGN_COL, 0,                   END_COL,
              BGN_COL,    1,                END_COL,
  SET_DIV, 5, BGN_COL,      2, 3, 4, 5, 6,  END_COL,
  SET_DIV, 1, BGN_COL,                  6,  END_COL,
  SET_DIV, 1, BGN_COL,                  6,  END_COL,
  SET_DIV, 1, BGN_COL,                  6,  END_COL,
  SKIP_COL,
  EOD
};

const uint8_t Letter_D2[] = {  
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 2, BGN_COL, 0,                6, END_COL,
              BGN_COL, 0,                6, END_COL,
              BGN_COL,    1,          5,    END_COL,
  SET_DIV, 3, BGN_COL,       2, 3, 4,       END_COL,
  EOD
};

const uint8_t Letter_E2[] = {
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,
              BGN_COL, 0,       3,       6, END_COL,
              BGN_COL, 0,       3,       6, END_COL,
  SET_DIV, 2, BGN_COL, 0,                6, END_COL,
  EOD
};

const uint8_t Letter_space[] = {
  SKIP_COL, SKIP_COL, SKIP_COL,
  EOD
};

// glyph not found (character substitution)
const uint8_t Letter_tofu[] = {
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 4, BGN_COL, 0,    2,    4,    6, END_COL,
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,
  SET_DIV, 4, BGN_COL, 0,    2,    4,    6, END_COL,
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  EOD
};

const uint8_t Letter_T2[] = {
  SET_DIV, 1, BGN_COL,                   6, END_COL,
  SET_DIV, 1, BGN_COL,                   6, END_COL,
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 1, BGN_COL,                   6, END_COL,
  SET_DIV, 1, BGN_COL,                   6, END_COL,
  EOD
};

const uint8_t Letter_F2[] = {
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 2, BGN_COL,          3,       6, END_COL,
  SET_DIV, 2, BGN_COL,          3,       6, END_COL,
  SET_DIV, 2, BGN_COL,          3,       6, END_COL,
  SET_DIV, 1, BGN_COL,                   6, END_COL,
  EOD
};

const uint8_t Letter_62[] = {
  SET_DIV, 4, BGN_COL,    1, 2, 3, 4,       END_COL,
  SET_DIV, 3, BGN_COL, 0,       3,    5,    END_COL,
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,
  SET_DIV, 2, BGN_COL,    1, 2,             END_COL,
  EOD
};

const uint8_t Letter_K2[] = {
  SET_DIV, 7, BGN_COL, 0, 1, 2, 3, 4, 5, 6, END_COL,
  SET_DIV, 1, BGN_COL,          3,          END_COL,
  SET_DIV, 2, BGN_COL,       2,    4,       END_COL,
  SET_DIV, 2, BGN_COL,    1,          5,    END_COL,
  SET_DIV, 2, BGN_COL, 0,                6, END_COL,
  EOD
};

const uint8_t Letter_S2[] = {
  SET_DIV, 3, BGN_COL,   1,        4, 5,    END_COL,
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,  
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,  
  SET_DIV, 3, BGN_COL, 0,       3,       6, END_COL,
  SET_DIV, 3, BGN_COL,   1, 2,        5,    END_COL,
  EOD
};

const uint8_t Letter_Y2[] = {
  SET_DIV, 3, BGN_COL,             4, 5, 6, END_COL,
  SET_DIV, 1, BGN_COL,          3,          END_COL,
  SET_DIV, 3, BGN_COL, 0, 1, 2,             END_COL,
  SET_DIV, 1, BGN_COL,          3,          END_COL,
  SET_DIV, 3, BGN_COL,             4, 5, 6, END_COL,
  EOD
};

const uint8_t Letter_dot[] = {
  SKIP_COL,
  SET_DIV, 2, BGN_COL, 0, 1,                END_COL,
  SET_DIV, 2, BGN_COL, 0, 1,                END_COL,
  SKIP_COL, SKIP_COL,
  EOD
};
