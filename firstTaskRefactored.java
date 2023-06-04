private static final Set<String> SUSPICIOUS_NAMES = Set.of(
	"Don", "John"
);

void checkSecurity(String[] people)
{
	for (String person : people)
	{
		if (SUSPICIOUS_NAMES.contains(person))
		{
			sendAlert(); 
			return;
		}
	}
}