/* Menu options
 *
 * Edit guide.
 * FilamentX[]:       Enter all options here.
 * FilamentXLenght:   The length of the array.
 * FilamentXPosition: The index of the value of the array. Currently is 0, so the default value is the first one in the array.
 * FilamentX:         The selected value.
 * TODO: Make length by getting actual array length dynamically, not manually added.
 *  
 * NOTE: Remember to start counting length from 0.
 * NOTE: Compensation factor is a certain about of meters to remove from the output. Atleast 1m is used for the hose. 
 * NOTE: Calibration factor is used for the loadcell to show the correct value. Use the FilamentCalira
 * NOTE: TimeOutSec is how many seconds it will take for the program to time out and go to stand by.
 * 
 */

float   CalibrationFactor           = -834699.93;
int     TimeOutSec                  = 120;
float   CompensationFactor          = 1.5; 
float   FilamentTotalWeight         = 0;
int     SelectionPrevious           = 0;
int     SelectionNext               = 0;

String  FilamentSpools[]            = {"3D4M-Transparant", "3D4M-Dof", "Form Futura","Black", "Cardboard", "No Spool"};
float   FilamentSpoolWeights[]      = {230.0, 220.0, 210.0, 250.0, 160.0, 0.0};
int     FilamentSpoolLength         = 5;
int     FilamentSpoolPosition       = 0;
float   FilamentSpoolWeight         = FilamentSpoolWeights[FilamentSpoolPosition];
String  FilamentSpool               = FilamentSpools[FilamentSpoolPosition];

String  FilamentMaterials[]         = {"PLA", "PET-G", "Facilan C8", "ABS", "ASA", "DSM NY Cabrbon","DSM TPU", "Facilan HT", "MetalFil(Bronze/Copper)"};
float   FilamentMaterialDensities[] = {1.25, 1.27, 1.40, 1.07, 1.04, 1.17, 1.10, 1.30, 3.50};
int     FilamentMaterialLength      = 8;
int     FilamentMaterialPosition    = 0;
float   FilamentMaterialDensity     = FilamentMaterialDensities[FilamentMaterialPosition];
String  FilamentMaterial            = FilamentMaterials[FilamentMaterialPosition];

float   FilamentDiameters[]         = {2.85, 1.75};
int     FilamentDiameterLength      = 1;
int     FilamentDiameterPosition    = 0;
float   FilamentDiameter            = FilamentDiameters[FilamentDiameterPosition];
