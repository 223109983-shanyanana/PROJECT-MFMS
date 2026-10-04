#include <stdio.h>
#include <string.h>
#include "assets.h"

void addAsset(Asset assets[], int *assetCount)
{
if (*assetCount >= MAX_ASSETS)
{
printf("\nAsset storage is full.\n");
return;
}

printf("\n===== ADD ASSET =====\n");

printf("Enter Asset ID: ");
scanf("%19s", assets[*assetCount].assetID);

printf("Enter Asset Name: ");
scanf(" %49[^\n]", assets[*assetCount].assetName);

printf("Enter Asset Type: ");
scanf(" %29[^\n]", assets[*assetCount].assetType);

do
{
printf("Enter Purchase Value: N$");
scanf("%f", &assets[*assetCount].purchaseValue);

if (assets[*assetCount].purchaseValue < 0)
{
printf("Purchase value cannot be negative.\n");
}

} while (assets[*assetCount].purchaseValue < 0);

printf("Enter Department: ");
scanf(" %49[^\n]", assets[*assetCount].department);

printf("Enter Condition: ");
scanf(" %29[^\n]", assets[*assetCount].condition);

(*assetCount)++;

printf("\nAsset added successfully!\n");
}

void displayAssets(Asset assets[], int assetCount)
{
int i;

if (assetCount == 0)
{
printf("\nNo assets have been registered.\n");
return;
}

printf("\n========== MUNICIPAL ASSETS ==========\n");

for (i = 0; i < assetCount; i++)
{
printf("\nAsset %d\n", i + 1);
printf("Asset ID: %s\n", assets[i].assetID);
printf("Asset Name: %s\n", assets[i].assetName);
printf("Asset Type: %s\n", assets[i].assetType);
printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
printf("Department: %s\n", assets[i].department);
printf("Condition: %s\n", assets[i].condition);
printf("--------------------------------------\n");
}
}

void searchAsset(Asset assets[], int assetCount)
{
char searchID[20];
int i;
int found = 0;

if (assetCount == 0)
{
printf("\nNo assets have been registered.\n");
return;
}

printf("\n===== SEARCH ASSET =====\n");
printf("Enter Asset ID: ");
scanf("%19s", searchID);

for (i = 0; i < assetCount; i++)
{
if (strcmp(assets[i].assetID, searchID) == 0)
{
printf("\nAsset Found!\n");
printf("Asset ID: %s\n", assets[i].assetID);
printf("Asset Name: %s\n", assets[i].assetName);
printf("Asset Type: %s\n", assets[i].assetType);
printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
printf("Department: %s\n", assets[i].department);
printf("Condition: %s\n", assets[i].condition);

found = 1;
break;
}
}

if (!found)
{
printf("\nAsset not found.\n");
}
}