typedef struct s_defs{
  char  north_wall_texture[MAX_PATH_LENGTH];
  char  south_wall_texture[MAX_PATH_LENGTH];
  char  west_wall_texture[MAX_PATH_LENGTH];
  char  east_wall_texture[MAX_PATH_LENGTH];
  int floor_color[3];
  int ceiling_color[3];
  char  *map; // Explicação no ficheiro .md
} t_defs;
