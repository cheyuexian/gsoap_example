#include "wsdd.nsmap"
#include "wsddapi.h"
int main(int argc, char** argv)
{
	const char * endpoint = "";
	const char * type = NULL;
	const char * scope = NULL;
	int c = 0;
    const char* url="soap.udp://239.255.255.250:3702";
	// while ((c = getopt (argc, argv, "r:t:s:")) != -1)
	// {
	// 	switch (c)
	// 	{
	// 		case 'r': endpoint = optarg; break;
	// 		case 't': type     = optarg; break;
	// 		case 's': scope    = optarg; break;
	// 		default:
	// 			std::cout << int(c) << std::endl;
	// 			std::cout << argv[0] << std::endl;
	// 			std::cout << "\t -r <endpoint>        : resolve endpoint" << std::endl;
	// 			std::cout << "\t -t <type> -s <scope> : probe for type/scope" << std::endl;
	// 			exit(0);
	// 		break;
	// 	}
	// }
	// if (optind<argc)
	// {
	// 	url = argv[optind];
	// }
	
      	int res = 0;
	// if (url.find("soap.udp:")==0)
	// {	
		//td::cout << "to multicast" << std::endl;
		
		// create soap instance
		struct soap* serv = soap_new1(SOAP_IO_UDP); 
		if (!soap_valid_socket(soap_bind(serv, NULL, 0, 1000)))
		{
			soap_print_fault(serv, stderr);
			exit(1);
		}	

		res = soap_wsdd_Probe(serv,
			  SOAP_WSDD_ADHOC,      // mode
			  SOAP_WSDD_TO_TS,      // to a TS
			  "soap.udp://239.255.255.250:3702",         // address of TS
			  soap_wsa_rand_uuid(serv),                   // message ID
			  NULL,                 // ReplyTo
			  type,
			  scope,
			  NULL);
		// call resolve or probe
		// if (strlen(endpoint) == 0)
		// {		
		// 	res = soap_wsdd_Probe(serv,
		// 	  SOAP_WSDD_ADHOC,      // mode
		// 	  SOAP_WSDD_TO_TS,      // to a TS
		// 	  "soap.udp://239.255.255.250:3702",         // address of TS
		// 	  soap_wsa_rand_uuid(serv),                   // message ID
		// 	  NULL,                 // ReplyTo
		// 	  type,
		// 	  scope,
		// 	  NULL);
		// }
		// else
		// {	
		// 	// send resolve request
		// 	res = soap_wsdd_Resolve(serv,
		// 	  SOAP_WSDD_ADHOC,      // mode
		// 	  SOAP_WSDD_TO_TS,      // to a TS
		// 	  "soap.udp://239.255.255.250:3702",         // address of TS
		// 	  soap_wsa_rand_uuid(serv),                   // message ID
		// 	  NULL,                 // ReplyTo
		// 	  endpoint);
		// }
		printf("res=%d\n",res);
		if (res != SOAP_OK)
		{
			soap_print_fault(serv, stderr);
		}
				
		// listen answers
		soap_wsdd_listen(serv, -1000000);
	// }
	// else
	// {
	// 	std::cout << "to proxy" << std::endl;
		
	// 	struct soap* serv = soap_new(); 
	// 	if (strlen(endpoint) == 0)
	// 	{		
	// 		res = soap_wsdd_Probe(serv,
	// 		  SOAP_WSDD_MANAGED,      // mode
	// 		  SOAP_WSDD_TO_DP,      // to a Proxy
	// 		  url.c_str(),         // address of Proxy
	// 		  soap_wsa_rand_uuid(serv),                   // message ID
	// 		  NULL,                 // ReplyTo
	// 		  type,
	// 		  scope,
	// 		  NULL);
	// 	}
	// 	else
	// 	{	
	// 		// send resolve request
	// 		res = soap_wsdd_Resolve(serv,
	// 		  SOAP_WSDD_MANAGED,      // mode
	// 		  SOAP_WSDD_TO_DP,      // to a Proxy
	// 		  url.c_str(),         // address of Proxy
	// 		  soap_wsa_rand_uuid(serv),                   // message ID
	// 		  NULL,                 // ReplyTo
	// 		  endpoint);
	// 	}
		
	// 	if (res != SOAP_OK)
	// 	{
	// 		soap_print_fault(serv, stderr);
	// 	}
	// }
	
	return 0;
}

// template <class T> 
// void printMatch(const T & match)
// {
// 	std::cout << "===================================================================" << std::endl;
// 	if (match.wsa__EndpointReference.Address)
// 	{
// 		std::cout << "Endpoint:\t"<< match.wsa__EndpointReference.Address << std::endl;
// 	}
// 	if (match.Types)
// 	{
// 		std::cout << "Types:\t\t"<< match.Types<< std::endl;
// 	}
// 	if (match.Scopes)
// 	{
// 		if (match.Scopes->__item )
// 		{
// 			std::cout << "Scopes:\t\t"<< match.Scopes->__item << std::endl;
// 		}
// 		if (match.Scopes->MatchBy)
// 		{
// 			std::cout << "MatchBy:\t"<< match.Scopes->MatchBy << std::endl;
// 		}
// 	}
// 	if (match.XAddrs)
// 	{
// 		std::cout << "XAddrs:\t\t"<< match.XAddrs << std::endl;
// 	}
// 	std::cout << "MetadataVersion:\t\t" << match.MetadataVersion << std::endl;
// 	std::cout << "-------------------------------------------------------------------" << std::endl;
// }

SOAP_FMAC5 int SOAP_FMAC6 SOAP_ENV__Fault(struct soap* soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail) {
	printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}


SOAP_FMAC5 int SOAP_FMAC6 __tdn__Hello(struct soap* soap, struct wsdd__HelloType tdn__Hello, struct wsdd__ResolveType *tdn__HelloResponse) {
	printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __tdn__Bye(struct soap* soap, struct wsdd__ByeType tdn__Bye, struct wsdd__ResolveType *tdn__ByeResponse) {
	printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __tdn__Probe(struct soap* soap, struct wsdd__ProbeType tdn__Probe, struct wsdd__ProbeMatchesType *tdn__ProbeResponse) {
	printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
void wsdd_event_ProbeMatches(struct soap *soap, unsigned int InstanceId, 
const char *SequenceId, unsigned int MessageNumber, const char *MessageID, 
const char *RelatesTo, struct wsdd__ProbeMatchesType *matches)
{
	printf("wsdd_event_ProbeMatches tid:%s RelatesTo:%s nbMatch:%d\n", 
    MessageID, RelatesTo, matches->__sizeProbeMatch);

    printf("ProbeMatch %s \n",matches->ProbeMatch->XAddrs);
        // for (int i=0; i < matches->__sizeProbeMatch; ++i)
        // {
        //         wsdd__ProbeMatchType& elt = matches->ProbeMatch[i];
		// printMatch(elt);
        // }
}

void wsdd_event_ResolveMatches(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ResolveMatchType *match)
{
	printf("wsdd_event_ResolveMatches tid:%s RelatesTo:%s\n", MessageID, RelatesTo);
	//printMatch(*match);
}

void wsdd_event_Hello(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int MetadataVersion)
{
}

void wsdd_event_Bye(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int *MetadataVersion)
{
}

soap_wsdd_mode wsdd_event_Resolve(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *EndpointReference, struct wsdd__ResolveMatchType *match)
{
	return SOAP_WSDD_ADHOC;
}

soap_wsdd_mode wsdd_event_Probe(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *Types, const char *Scopes, const char *MatchBy, struct wsdd__ProbeMatchesType *matches)
{
	return SOAP_WSDD_ADHOC;
}