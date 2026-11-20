#ifndef YEAR_DATA_H
#define YEAR_DATA_H

#define YEAR_START 2005
#define YEAR_END   2024
#define YEAR_COUNT 20

typedef struct {
    int year;
    int collision_id;
    int severity;
} YearCsvRow;

typedef struct {
    int accidents;
    int killed;
    int severe_injury;
    int light_injury;
    int unharmed;
    int last_collision_id;
    int has_last_collision;
} YearStats;

typedef struct {
    YearStats years[YEAR_COUNT];
} YearTable;

int year_to_index(int year);
void year_table_init(YearTable *table);
void year_table_add_row(YearTable *table, const YearCsvRow *row);

void compute_year_stats(const YearTable *table, int year, YearStats *out_stats);
void run_year_menu(const YearTable *table);

#endif